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
