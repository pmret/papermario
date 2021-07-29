from itertools import zip_longest
from math import ceil

def iter_in_groups(iterable, n, fillvalue=None):
    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)

def iter_image_indexes(width, height, bytes_per_x=1, bytes_per_y=1, flip_h=False, flip_v=False):
    w = int(width * bytes_per_x)
    h = int(height * bytes_per_y)

    xrange = range(w - ceil(bytes_per_x), -1, -ceil(bytes_per_x)) if flip_h else range(0, w, ceil(bytes_per_x))
    yrange = range(h - ceil(bytes_per_y), -1, -ceil(bytes_per_y)) if flip_v else range(0, h, ceil(bytes_per_y))

    for y in yrange:
        for x in xrange:
            yield x, y, (y * w) + x
