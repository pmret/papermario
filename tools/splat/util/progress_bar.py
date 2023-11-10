import tqdm
import sys

out_file = sys.stderr


def get_progress_bar(elements: list) -> tqdm.tqdm:
    return tqdm.tqdm(elements, total=len(elements), file=out_file)
