extends Node3D

@export
var start_position_x := -2000.0

@export
var start_position_y := 344800.0

@export
var tile_size_meters := 1000.0

@export
var tile_size_pixels := 1000

@export
var heightmap_data_path: String

@export
var ortho_data_path: String


func _ready():
	var heightmap_data = Geodot.get_raster_layer(heightmap_data_path)
	var ortho_data = Geodot.get_raster_layer(ortho_data_path)
	
	var img = heightmap_data.get_image(
		start_position_x,
		start_position_y,
		tile_size_meters,
		tile_size_pixels,
		0
	)
	var ortho = ortho_data.get_image(
		start_position_x,
		start_position_y,
		tile_size_meters,
		tile_size_pixels * 4,
		1
	)
	
	get_node("MeshInstance").mesh.surface_get_material(0).set_shader_param("heightmap", img.get_image_texture())
	get_node("MeshInstance").mesh.surface_get_material(0).set_shader_param("ortho", ortho.get_image_texture())
