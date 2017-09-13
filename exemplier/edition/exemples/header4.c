/**
 * Unmasks the data from the given mask. It means that the pixels are set to
 * the pixel value of the reference image when the related label in the mask
 * is 0.
 * @param mask the region map that is used as a mask.
 * @param reference	the image that is used as a reference.
 * @return true if the reference is successfully masked, false otherwise.
 */
int unmask(const int* mask, const int* reference) {
    ...
    return true;
}
