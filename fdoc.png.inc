<?php

 /**
   * @file
   * Library containing functions to process png files.
   *   
   */

/**
 * 
 * @ingroup fdoc
 *
 * Process png file
 *
 */
function process($file) {
  $location = file_create_url($file->uri);
  $img_tag = '<img src="'. $location .'">';
  
  return $img_tag;
}
