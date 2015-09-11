<?php

 /**
   * @file
   * Library containing functions to process gif files.
   *   
   */

/**
 * 
 * @ingroup fdoc
 *
 * Process gif file
 *
 */
function process($file) {
  $location = file_create_url($file->uri);
  $img_tag = '<img src="'. $location .'">';
  
  return $img_tag;
}
