<?php
  
  // include DLS rest library
  module_load_include('inc', 'dls_rest_routes', '/includes/models/dls_rest_routes.rest_routes');
  module_load_include('inc', 'dls_resource', '/includes/library/dls_resource.resource_interface');

  class RestRoutesResource implements ResourceInterface {
    
    var $url; 
    
    public function __construct($group, $name) {
      $url = RestRoutes::get()->getPathWithCredentialsFor($group, $name);
      $this->url = $url;
    }
    
    public function get($id) {
      $endpoint = $this->url . '/' . $id;
      $options = array(
        'method' => 'GET',
        'timeout' => 30,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
      );
      $response = drupal_http_request($endpoint, $options)->data;
      return json_decode($response);
    }
    
    public function getRaw($id) {
      $endpoint = $this->url . '/' . $id;
      $options = array(
        'method' => 'GET',
        'timeout' => 30,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
      );
      $response = drupal_http_request($endpoint, $options)->data;
      return $response;
    }
    
    public function getAll() {
      $endpoint = $this->url;
      $options = array(
        'method' => 'GET',
        'timeout' => 30,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
      );
      $response = drupal_http_request($endpoint, $options)->data;
      return json_decode($response);
    }
    
    public function getWhere($params) {
      $endpoint = $this->url;
      $options = array(
        'method' => 'POST',
        'timeout' => 30,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
        'data' => drupal_http_build_query($params),
      );
      $response = drupal_http_request($endpoint, $options)->data;
      return json_decode($response);
    }
    
    public function update($id, $params) {
      $endpoint = $this->url . '/' . $id;
      $options = array(
        'method' => 'PUT',
        'timeout' => 30,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
        'data' => drupal_http_build_query($params),
      );
      $response = drupal_http_request($endpoint, $options)->data;
      return json_decode($response);
    }
    
    public function delete($id) {
      $endpoint = $this->url . '/' . $id;
      $options = array(
        'method' => 'DELETE',
        'timeout' => 30,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
      );
      $response = drupal_http_request($endpoint, $options)->data;
      return json_decode($response);
    }
    
    public function create($params) {
      $endpoint = $this->url;
      $options = array(
        'method' => 'POST',
        'timeout' => 30,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
        'data' => drupal_http_build_query($params),
      );
      $response = drupal_http_request($endpoint, $options)->data;
      return json_decode($response);
    }
  }