<?php

  module_load_include('inc', 'dls_resource', '/includes/library/dls_resource.resource_interface');

  class MockResource implements ResourceInterface {
    var $model;
    
    public function looksLike($jsonString) {
      $this->model = $jsonString;
    }
    
    public function get($id) {
      $item = json_decode($this->model);
      $item->ID = $id;
      return $item;
    }
    
    public function getAll() {
      $list = array();
      for($i=0; $i<100; $i++) {
        $item = json_decode($this->model);
        $item->ID = ($i + 1);
        $list[] = $item;
      }
      return $list;
    }
    
    public function getWhere($params, $limit = 25) {
      $list = array();
      for($i=0; $i<$limit; $i++) {
        $item = json_decode($this->model);
        $item->ID = 1 + (2*$i);
        $list[] = $item;
      }
      return $list;
    }
    
    public function update($id, $params) {
      $item = json_decode($this->model);
      $item->ID = $id;
      foreach($params as $key => $value) {
        $item->$key = $value;
      }
      return $item;
    }
    
    public function delete($id) {
      $item = json_decode($this->model);
      $item->ID = $id;
      return $item;
    }
    
    public function create($params) {
      $item = json_decode($this->model);
      $item->ID = 1;
      foreach($params as $key => $value) {
        $item->$key = $value;
      }
      return $item;
    }
    
  }