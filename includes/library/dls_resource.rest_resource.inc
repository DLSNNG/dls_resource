<?php
  
  // include DLS rest library
  module_load_include('inc', 'dls', '/includes/dls.rest');
  module_load_include('inc', 'dls_resource', '/includes/library/dls_resource.resource_interface');

  class RestResource implements ResourceInterface {
    
    var $url; 
    
    public function __construct($url) {
      $this->url = $url;
    }
    
    public function get($id) {
      $endpoint = $this->url . '/' . $id;
      return dls_rest_get($endpoint);
    }
    
    public function getAll() {
      return dls_rest_get($this->url);  
    }
    
    public function getWhere($params) {
      $endpoint = $this->url . '/query';
      return dls_rest_post($endpoint, $params);
    }
    
    public function update($id, $params) {
      $endpoint = $this->url . '/' . $id;
      return dls_rest_put($id, $params);
    }
    
    public function delete($id) {
      $endpoint = $this->url . '/' . $id;
      return dls_rest_delete($endpoint, array());
    }
    
    public function create($params) {
      $endpoint = $this->url;
      return dls_rest_post($endpoint, $params);
    }
  }