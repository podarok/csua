<?php

/**
 * @file
 * Spain.
 */

/**
 * Returns an associative array of states/territories.
 */
function location_province_list_es() {
  return array(
    'AL' => "Alava",
    'AB' => "Albacete",
    'AC' => "Alicante",
    'AM' => "Almeria",
    'AS' => "Asturias",
    'AV' => "Avila",
    'BJ' => "Badajoz",
    'IB' => "Illes Balears",
    'BA' => "Barcelona",
    'BU' => "Burgos",
    'CC' => "Caceres",
    'CZ' => "Cadiz",
    'CT' => "Cantabria",
    'CL' => "Castellon",
    'CR' => "Ciudad Real",
    'CD' => "Cordoba",
    'CA' => "A Coruna",
    'CU' => "Cuenca",
    'GI' => "Girona",
    'GD' => "Granada",
    'GJ' => "Guadalajara",
    'GP' => "Guipuzcoa",
    'HL' => "Huelva",
    'HS' => "Huesca",
    'JN' => "Jaen",
    'RJ' => "La Rioja",
    'LE' => "Leon",
    'LL' => "Lleida",
    'LG' => "Lugo",
    'MD' => "Madrid",
    'ML' => "Malaga",
    'MU' => "Murcia",
    'NV' => "Navarra",
    'OU' => "Ourense",
    'PL' => "Palencia",
    'PM' => "Las Palmas",
    'PO' => "Pontevedra",
    'SL' => "Salamanca",
    'SC' => "Santa Cruz de Tererife",
    'SG' => "Segovia",
    'SV' => "Sevilla",
    'SO' => "Soria",
    'TA' => "Tarragona",
    'TE' => "Teruel",
    'TO' => "Toledo",
    'VC' => "Valencia",
    'VD' => "Valladolid",
    'VZ' => "Vizcaya",
    'ZM' => "Zamora",
    'ZR' => "Zaragoza"
  );
}

/**
 * Link providers.
 */
function location_map_link_es_providers() {
  return array(
    'google' => array(
      'name' => 'Mapas Google',
      'url' => 'http://maps.google.es',
      'tos' => 'http://www.google.com/intl/es_es/help/terms_maps.html',
    ),
  );
}

/**
 * Default providers.
 */
function location_map_link_es_default_providers() {
  return array('google');
}

/**
 * Returns a lat/lon pair of the approximate center of the given postal code in the given country
 *
 * @param $location
 *   An associative array $location where
 *     'street'       => the street portion of the location
 *     'supplemental' => additional street portion of the location
 *     'province'     => the province, state, or territory
 *     'country'      => lower-cased two-letter ISO code (REQUIRED)
 *     'postal_code'  => the international postal code for this location (REQUIRED)
 *
 * @return
 *   An associative array where
 *      'lat' => approximate latitude of the center of the postal code's area
 *      'lon' => approximate longitude of the center of the postal code's area
 *
 */
function location_map_link_es_google($location = array()) {
  $query_params = array();

  foreach (array('street', 'city', 'postal_code', 'country') as $field) {
    if (isset($location[$field])) {
      $query_params[] = $location[$field];
    }
  }

  if (count($query_params)) {
    return ('http://maps.google.es?q='. urlencode(implode(', ', $query_params)));
  }
  else {
    return NULL;
  }
}
