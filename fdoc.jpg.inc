<?php

 /**
   * @file
   * Library containing functions to process jpeg/jpg files.
   *   
   */

/**
 * 
 * @ingroup fdoc
 *
 * Process jpeg/jpg file
 *
 */
function process($file) {
  $location = file_create_url($file->uri);
  $img_tag = '<img src="'. $location .'">';
  
  return $img_tag;
}
