/*
    Copyright (c) 2014,  Anonymous Meerkat<meerkatanonymous@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Nightmare Project nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <libgimp/gimp.h>
#include <string.h>

void query();
static void run   (const gchar      *name,
                   gint              nparams,
                   const GimpParam  *param,
                   gint             *nreturn_vals,
                   GimpParam       **return_vals);


GimpPlugInInfo PLUG_IN_INFO = {
    NULL,
    NULL,
    query,
    run
};

MAIN();

void query() {
    static GimpParamDef args[] = {
        {
            GIMP_PDB_INT32,
            "run-mode",
            "Run mode"
        },
        {
            GIMP_PDB_IMAGE,
            "image",
            "Input image"
        },
        {
            GIMP_PDB_DRAWABLE,
            "drawable",
            "Input drawable"
        }
    };

    gimp_install_procedure(
        "plug-in-nmelevelexport",
        "Nightmare Level Export",
        "Exports relevant layers into a Nightmare level",
        "Anonymous Meerkat",
        "Copyright Anonymous Meerkat",
        "2014",
        "NME Level Export",
        "RGB*, GRAY*",
        GIMP_PLUGIN,
        G_N_ELEMENTS (args), 0,
        args, NULL);

        gimp_plugin_menu_register ("plug-in-nmelevelexport",
                                   "<Image>/Image/");
}

static void
  run (const gchar      *name,
       gint              nparams,
       const GimpParam  *param,
       gint             *nreturn_vals,
       GimpParam       **return_vals)
{
    static GimpParam  values[1];
    GimpPDBStatusType status = GIMP_PDB_SUCCESS;
    GimpRunMode       run_mode;

    /* Setting mandatory output values */
    *nreturn_vals = 1;
    *return_vals  = values;

    values[0].type = GIMP_PDB_STATUS;
    values[0].data.d_status = status;

    char* prefix = "/tmp"

    gint num_layers;
    gint* layers = gimp_image_get_layers(param[1].data.d_image, &num_layers);

    int i;
    for (i = 0; i < num_layers; i++) {
        g_message(gimp_item_get_name(layers[i]));
        gimp_item_set_visible(layers[i], 0);
    }

    char* layername;
    char filename[4096];
    for (i = 0; i < num_layers; i++) {
        layername = gimp_item_get_name(layers[i]);
        strcpy(filename, prefix);
        strcat(filename, "/");
        strcat(filename, layername);
        strcat(filename, ".png");
        gimp_item_set_visible(layers[i], 1);
        gimp_file_save(GIMP_RUN_NONINTERACTIVE, param[1].data.d_image, layers[i], filename, filename);
    }
}
