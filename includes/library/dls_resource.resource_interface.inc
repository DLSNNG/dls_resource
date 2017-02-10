<?php

  interface ResourceInterface {
    public function get($id);
    public function getAll();
    public function getWhere($params);
    public function update($id, $params);
    public function delete($id);
    public function create($params);
  }