<?php

 /**
   * @file
   * Library containing functions to parse html files.
   *   
   */

/**
 * 
 * @ingroup fdoc
 *
 * Parse html file
 *
 */
function parse($file) {
  $realpath = drupal_realpath($file->uri);
  $fh = fopen($realpath, 'r');
  $rs = '';
  
  while(($row = fgets($fh)) !== FALSE){
    if ($row != "\n" && $row != "\r\n") {	
      $rs .= $row;  
	}
  }
  fclose($fh);
  return $rs;
}
