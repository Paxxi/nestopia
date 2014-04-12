/*
 * Nestopia UE
 * 
 * Copyright (C) 2012-2014 R. Danbrook
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include "../main.h"
#include "../config.h"

#include "gtkui.h"
#include "gtkui_callbacks.h"
#include "gtkui_config.h"

extern settings_t conf;

GtkWidget *configwindow;

GtkWidget *gtkui_config() {
	// Create the Configuration window
	
	configwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(configwindow), "Configuration");
	
	GtkWidget *box_upper = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget *box_lower = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget *notebook = gtk_notebook_new();
	
	gtk_container_add(GTK_CONTAINER(configwindow), box_upper);
	
	// Video //
	GtkWidget *box_video = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	
	// Filter
	GtkWidget *box_video_filter = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_filter = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "Filter:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *combo_video_filter = gtk_widget_new(
				GTK_TYPE_COMBO_BOX_TEXT,
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_filter), "None");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_filter), "NTSC");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_filter), "xBR");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_filter), "HqX");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_filter), "2xSaI");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_filter), "ScaleX");
	
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo_video_filter), conf.video_filter);
	
	gtk_box_pack_start(GTK_BOX(box_video_filter), label_video_filter, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_filter), combo_video_filter, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_filter, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(combo_video_filter), "changed",
		G_CALLBACK(gtkui_cb_video_filter), NULL);
	
	// Scale Factor
	GtkWidget *box_video_scale = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_scale = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "Scale Factor:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *combo_video_scale = gtk_widget_new(
				GTK_TYPE_COMBO_BOX_TEXT,
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_scale), "1x");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_scale), "2x");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_scale), "3x");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_scale), "4x");
		
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo_video_scale), conf.video_scale_factor - 1);
	
	gtk_box_pack_start(GTK_BOX(box_video_scale), label_video_scale, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_scale), combo_video_scale, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_scale, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(combo_video_scale), "changed",
		G_CALLBACK(gtkui_cb_video_scale), NULL);
	
	// Palette Mode
	GtkWidget *box_video_palette = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_palette = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "Palette Mode:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *combo_video_palette = gtk_widget_new(
				GTK_TYPE_COMBO_BOX_TEXT,
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_palette), "YUV");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_palette), "RGB");
		
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo_video_palette), conf.video_palette_mode);
	
	gtk_box_pack_start(GTK_BOX(box_video_palette), label_video_palette, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_palette), combo_video_palette, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_palette, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(combo_video_palette), "changed",
		G_CALLBACK(gtkui_cb_video_palette), NULL);
	
	// YUV Decoder
	GtkWidget *box_video_decoder = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_decoder = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "YUV Decoder:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *combo_video_decoder = gtk_widget_new(
				GTK_TYPE_COMBO_BOX_TEXT,
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_decoder), "Consumer");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_decoder), "Canonical");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_decoder), "Alternative");
		
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo_video_decoder), conf.video_decoder);
	
	gtk_box_pack_start(GTK_BOX(box_video_decoder), label_video_decoder, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_decoder), combo_video_decoder, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_decoder, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(combo_video_decoder), "changed",
		G_CALLBACK(gtkui_cb_video_decoder), NULL);
	
	// NTSC Mode
	GtkWidget *box_video_ntscmode = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_ntscmode = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "NTSC Mode:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *combo_video_ntscmode = gtk_widget_new(
				GTK_TYPE_COMBO_BOX_TEXT,
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_ntscmode), "Composite");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_ntscmode), "S-Video");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_ntscmode), "RGB");
		
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo_video_ntscmode), conf.video_ntsc_mode);
	
	gtk_box_pack_start(GTK_BOX(box_video_ntscmode), label_video_ntscmode, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_ntscmode), combo_video_ntscmode, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_ntscmode, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(combo_video_ntscmode), "changed",
		G_CALLBACK(gtkui_cb_video_ntscmode), NULL);
	
	// NTSC Mode
	GtkWidget *box_video_xbrrounding = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_xbrrounding = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "xBR Corner Rounding:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *combo_video_xbrrounding = gtk_widget_new(
				GTK_TYPE_COMBO_BOX_TEXT,
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_xbrrounding), "None");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_xbrrounding), "Some");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_video_xbrrounding), "All");
		
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo_video_xbrrounding), conf.video_xbr_corner_rounding);
	
	gtk_box_pack_start(GTK_BOX(box_video_xbrrounding), label_video_xbrrounding, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_xbrrounding), combo_video_xbrrounding, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_xbrrounding, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(combo_video_xbrrounding), "changed",
		G_CALLBACK(gtkui_cb_video_xbrrounding), NULL);
	
	// Brightness
	GtkAdjustment *adj_video_brightness = gtk_adjustment_new(conf.video_brightness, -100, 100, 1, 5, 0);
	GtkWidget *box_video_brightness = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_brightness = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "Brightness:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *scale_video_brightness = gtk_widget_new(
				GTK_TYPE_SCALE,
				"halign", GTK_ALIGN_START,
				"margin-left", MARGIN_LR,
				"orientation", GTK_ORIENTATION_HORIZONTAL,
				"adjustment", adj_video_brightness,
				"width-request", 201,
				"height-request", 32,
				"digits", 0,
				NULL);
	gtk_box_pack_start(GTK_BOX(box_video_brightness), label_video_brightness, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_brightness), scale_video_brightness, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_brightness, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(scale_video_brightness), "value-changed",
		G_CALLBACK(gtkui_cb_video_brightness), NULL);
	
	// Saturation
	GtkAdjustment *adj_video_saturation = gtk_adjustment_new(conf.video_saturation, -100, 100, 1, 5, 0);
	GtkWidget *box_video_saturation = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_saturation = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "Saturation:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *scale_video_saturation = gtk_widget_new(
				GTK_TYPE_SCALE,
				"halign", GTK_ALIGN_START,
				"margin-left", MARGIN_LR,
				"orientation", GTK_ORIENTATION_HORIZONTAL,
				"adjustment", adj_video_saturation,
				"width-request", 201,
				"height-request", 32,
				"digits", 0,
				NULL);
	gtk_box_pack_start(GTK_BOX(box_video_saturation), label_video_saturation, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_saturation), scale_video_saturation, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_saturation, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(scale_video_saturation), "value-changed",
		G_CALLBACK(gtkui_cb_video_saturation), NULL);
	
	// Contrast
	GtkAdjustment *adj_video_contrast = gtk_adjustment_new(conf.video_contrast, -100, 100, 1, 5, 0);
	GtkWidget *box_video_contrast = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_contrast = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "Contrast:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *scale_video_contrast = gtk_widget_new(
				GTK_TYPE_SCALE,
				"halign", GTK_ALIGN_START,
				"margin-left", MARGIN_LR,
				"orientation", GTK_ORIENTATION_HORIZONTAL,
				"adjustment", adj_video_contrast,
				"width-request", 201,
				"height-request", 32,
				"digits", 0,
				NULL);
	gtk_box_pack_start(GTK_BOX(box_video_contrast), label_video_contrast, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_contrast), scale_video_contrast, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_contrast, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(scale_video_contrast), "value-changed",
		G_CALLBACK(gtkui_cb_video_contrast), NULL);
	
	// Hue
	GtkAdjustment *adj_video_hue = gtk_adjustment_new(conf.video_hue, -45, 45, 1, 5, 0);
	GtkWidget *box_video_hue = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_video_hue = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "Hue:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *scale_video_hue = gtk_widget_new(
				GTK_TYPE_SCALE,
				"halign", GTK_ALIGN_START,
				"margin-left", MARGIN_LR,
				"orientation", GTK_ORIENTATION_HORIZONTAL,
				"adjustment", adj_video_hue,
				"width-request", 91,
				"height-request", 32,
				"digits", 0,
				NULL);
	gtk_box_pack_start(GTK_BOX(box_video_hue), label_video_hue, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video_hue), scale_video_hue, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_video), box_video_hue, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(scale_video_hue), "value-changed",
		G_CALLBACK(gtkui_cb_video_hue), NULL);
	
	// Audio //
	GtkWidget *box_audio = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	
	// Audio API
	GtkWidget *box_audio_api = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_audio_api = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "API:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *combo_audio_api = gtk_widget_new(
				GTK_TYPE_COMBO_BOX_TEXT,
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_audio_api), "SDL");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_audio_api), "libao");
		
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo_audio_api), conf.audio_api);
	
	gtk_box_pack_start(GTK_BOX(box_audio_api), label_audio_api, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_audio_api), combo_audio_api, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_audio), box_audio_api, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(combo_audio_api), "changed",
		G_CALLBACK(gtkui_cb_audio_api), NULL);
	
	// Sample Rate
	GtkWidget *box_audio_samplerate = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *label_audio_samplerate = gtk_widget_new(
				GTK_TYPE_LABEL,
				"label", "Sample Rate:",
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	GtkWidget *combo_audio_samplerate = gtk_widget_new(
				GTK_TYPE_COMBO_BOX_TEXT,
				"halign", GTK_ALIGN_START,
				"margin-bottom", MARGIN_TB,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_audio_samplerate), "11025Hz");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_audio_samplerate), "22050Hz");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_audio_samplerate), "44100Hz");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_audio_samplerate), "48000Hz");
	
	switch (conf.audio_sample_rate) {
		case 11025:
			gtk_combo_box_set_active(GTK_COMBO_BOX(combo_audio_samplerate), 0);
			break;
		case 22050:
			gtk_combo_box_set_active(GTK_COMBO_BOX(combo_audio_samplerate), 1);
			break;
		case 44100:
			gtk_combo_box_set_active(GTK_COMBO_BOX(combo_audio_samplerate), 2);
			break;
		case 48000:
			gtk_combo_box_set_active(GTK_COMBO_BOX(combo_audio_samplerate), 3);
			break;
		default:
			gtk_combo_box_set_active(GTK_COMBO_BOX(combo_audio_samplerate), 2);
			break;
	}
	
	gtk_box_pack_start(GTK_BOX(box_audio_samplerate), label_audio_samplerate, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_audio_samplerate), combo_audio_samplerate, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_audio), box_audio_samplerate, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(combo_audio_samplerate), "changed",
		G_CALLBACK(gtkui_cb_audio_samplerate), NULL);
	
	// Stereo
	GtkWidget *check_audio_stereo = gtk_widget_new(
				GTK_TYPE_CHECK_BUTTON,
				"label", "Stereo",
				"halign", GTK_ALIGN_START,
				"margin-left", MARGIN_LR,
				NULL);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_audio_stereo), conf.audio_stereo);
	
	gtk_box_pack_start(GTK_BOX(box_audio), check_audio_stereo, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(check_audio_stereo), "toggled",
		G_CALLBACK(gtkui_cb_audio_stereo), NULL);
	
	// Volume
	GtkAdjustment *adj_audio_volume = gtk_adjustment_new(conf.audio_volume, 0, 100, 1, 5, 0);
	GtkWidget *box_audio_volume = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *scale_audio_volume = gtk_widget_new(
				GTK_TYPE_SCALE,
				"halign", GTK_ALIGN_START,
				"margin-left", MARGIN_LR,
				"orientation", GTK_ORIENTATION_VERTICAL,
				"adjustment", adj_audio_volume,
				"width-request", 32,
				"height-request", 100,
				"inverted", TRUE,
				"digits", 0,
				NULL);
	gtk_box_pack_start(GTK_BOX(box_audio_volume), scale_audio_volume, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_audio), box_audio_volume, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(scale_audio_volume), "value-changed",
		G_CALLBACK(gtkui_cb_audio_volume), NULL);
	
	// Input //
	GtkWidget *box_input = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	
	// Misc //
	GtkWidget *box_misc = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	
	// Structuring the notebook
	GtkWidget *label_video = gtk_label_new("Video");
	GtkWidget *label_audio = gtk_label_new("Audio");
	GtkWidget *label_input = gtk_label_new("Input");
	GtkWidget *label_misc = gtk_label_new("Misc");
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box_video, label_video);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box_audio, label_audio);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box_input, label_input);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box_misc, label_misc);
	
	// The OK button
	GtkWidget *okbutton = gtk_widget_new(
				GTK_TYPE_BUTTON,
				"label", GTK_STOCK_OK,
				"halign", GTK_ALIGN_END,
				"margin-top", 8,
				"margin-bottom", 8,
				"margin-right", 8,
				NULL);
	gtk_button_set_use_stock(GTK_BUTTON(okbutton), TRUE);
	
	// Connect the OK button to a callback
	g_signal_connect(G_OBJECT(okbutton), "clicked",
		G_CALLBACK(gtkui_config_ok), NULL);
	
	// Structuring the window
	gtk_box_pack_start(GTK_BOX(box_upper), notebook, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box_upper), box_lower, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_lower), okbutton, FALSE, FALSE, 0);
	
	g_signal_connect(G_OBJECT(configwindow), "destroy",
		G_CALLBACK(gtkui_cb_destroy_config), NULL);
	
	gtk_widget_show_all(configwindow);
	
	return configwindow;
}

void gtkui_config_ok() {
	gtk_widget_destroy(configwindow);
}