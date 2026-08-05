#ifndef IMX708_DERM_H
#define IMX708_DERM_H

/* Pipeline configuration */
struct derm_config {
    int camera_count;
    int width;
    int height;
    int fps;
};

/* Pipeline results */
struct derm_result {
    double roi_area;
    double confidence;
    int control_signal;
};

/* API */
int derm_init(struct derm_config* cfg);
int derm_process_frame(const unsigned char* frame, struct derm_result* result);
void derm_cleanup(void);

#endif
