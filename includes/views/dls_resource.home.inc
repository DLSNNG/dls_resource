<?php

  module_load_include('inc', 'dls_resource', '/includes/library/dls_resource.rest_routes_resource');

  function view_dls_resource_home() {
    
    $resource = new RestRoutesResource('Resource', 'testing');
    $post = $resource->get(1);
    
    drupal_set_message($post->body);
    
    $block = array(
      '#type' => 'markup',
      '#markup' => 'testing',
    );
    return $block;
    
  }