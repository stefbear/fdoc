<?php

 /**
   * @file
   * Library containing functions to process
   * application/vnd.openxmlformats-officedocument.wordprocessingml.document
   * mime types as created by MS Word (docx).
   *
   */
   
define('DOCXZIP_ENTRY_NAME', "word/document.xml", true);

/**
 * 
 * @ingroup fdoc
 *
 * Process docx file
 *
 */
function process($file) {
  if (!$file) return;
  
  $filename = drupal_realpath($file->uri);
  if (!$filename || !file_exists($filename)) return;

  $zip = zip_open($filename);
  if (!$zip || is_numeric($zip)) return;

  $content = '';
  while ($zip_entry = zip_read($zip)) {
	if (zip_entry_open($zip, $zip_entry) == FALSE) continue;
    if (zip_entry_name($zip_entry) != DOCXZIP_ENTRY_NAME) continue;

    $content .= zip_entry_read($zip_entry, zip_entry_filesize($zip_entry));
    zip_entry_close($zip_entry);
  }
  zip_close($zip);      

  $content = str_replace('</w:r></w:p></w:tc><w:tc>', " ", $content);
  $content = str_replace('</w:r></w:p>', "\r\n", $content);
  $striped_content = strip_tags($content);

  return $content . exZImages($filename);
}

/**
  * Extract image(s) from zip archive to disk and return path of each image
  * 
  */  
function exZImages($filename) {
  if (!$filename) return;
  
  // open file
  $zip = new ZipArchive;
  if (true === $zip->open($filename)) {	
    // Loop through files to check for images
    $images = '';
    for ($i=0; $i<$zip->numFiles; $i++) {
      $zip_element = $zip->statIndex($i);
	  if (preg_match("([^\s]+(\.(?i)(jpg|jpeg|png|gif|bmp))$)", $zip_element['name'])) {
	    //todo: make sure we are not writing on top of exisiting files (filename).
		$zip->extractTo('public://', $zip_element['name']);
		$location = file_create_url('public://'.$zip_element['name']);
        $img_tag = '<img src="'. $location .'">';
		$images .= $img_tag;  
      }
    }
  }
  $zip->close();
  
  return $images;
}
