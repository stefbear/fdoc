<?php

 /**
   * @file
   * Library containing functions to process pdf files.
   *   
   */

/**
 * 
 * @ingroup fdoc
 *
 * Process pdf file
 *
 */
function process($file) {
  module_load_include('class', 'fdoc', 'fdoc.pdfparser');
  $location = file_create_url($file->uri);
  
  return PDFParser::parseFile($location);  
}
