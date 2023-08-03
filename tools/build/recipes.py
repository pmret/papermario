#!/usr/bin/env python3

import yaml
import argparse
from pathlib import Path
from typing import List, Dict


class DoubleRecipe:
    def __init__(self, entry: List[str], order: Dict[str, int]):
        order0 = order.get(entry[0], 99999)
        order1 = order.get(entry[1], 99999)
        if order0 <= order1 or order0 == 99999 or order1 == 99999:
            self.i = order0
            self.j = order1
            self.in1 = entry[0]
            self.in2 = entry[1]
        else:
            self.i = order1
            self.j = order0
            self.in1 = entry[1]
            self.in2 = entry[0]
        self.result = entry[2]
        self.used = False


def generate(in_yaml: Path, out_c: Path):
    with open(in_yaml) as f:
        data = yaml.load(f.read(), Loader=yaml.SafeLoader)

    products = data["Products"]
    mystery_products = data["MysteryProducts"]
    single_recipes = data["SingleRecipes"]
    double_recipes = data["DoubleRecipes"]
    records = data["CookingRecords"]

    dim = len(single_recipes)

    input_idx: Dict[str, int] = {}
    for idx, entry in enumerate(single_recipes):
        input_idx[entry[0]] = idx

    product_idx: Dict[str, int] = {}
    for idx, entry in enumerate(products):
        product_idx[entry[0]] = idx

    for recipe in single_recipes:
        if len(recipe) != 2 and len(recipe) != 3:
            raise Exception(f"Invaid format for ExtraDoubleRecipe: {str(recipe)}")
        if not recipe[1] in product_idx:
            raise Exception(f"Product {recipe[1]} for SingleRecipe {recipe[0]} not listed in Products")
        if len(recipe) == 3 and not recipe[2] in product_idx:
            raise Exception(f"Product {recipe[2]} for SingleRecipe {recipe[0]} not listed in Products")

    # double recipes with inputs not found in SingleRecipes are automatically treated as an ExtraDoubleRecipe
    for recipe in double_recipes:
        if len(recipe) != 3:
            raise Exception(f"Invaid format for ExtraDoubleRecipe: {str(recipe)}")
        #    if not recipe[0] in input_idx:
        #        raise Exception(f"Ingredient {recipe[0]} for DoubleRecipe ({recipe[0]}, {recipe[1]}) not listed in SingleRecipes")
        #    if not recipe[1] in input_idx:
        #        raise Exception(f"Ingredient {recipe[1]} for DoubleRecipe ({recipe[0]}, {recipe[1]}) not listed in SingleRecipes")
        if not recipe[2] in product_idx:
            raise Exception(f"Product {recipe[2]} for DoubleRecipe ({recipe[0]}, {recipe[1]}) not listed in Products")

    #    for recipe in extra_recipes:
    #        if len(recipe) != 3:
    #            raise Exception(f"Invaid format for ExtraDoubleRecipe: {str(recipe)}")
    #        if not recipe[2] in product_idx:
    #            raise Exception(f"Product {recipe[2]} for ExtraDoubleRecipe ({recipe[0]}, {recipe[1]}) not listed in Products")

    with open(out_c, "w") as f:
        f.write("/* This file is auto-generated. Do not edit. */\n\n")
        f.write('#include "common.h"\n\n')

        f.write(f"#define NUM_INGREDIENTS {dim}\n\n")

        f.write("s32 CookingIngredients[] = {\n")
        for recipe in single_recipes:
            f.write(f"    {recipe[0]},\n")
        f.write("    -1,\n")
        f.write("};\n\n")

        f.write("CookingResult CookingResults[] = {\n")
        for product in products:
            f.write(f"    {{ {product[1] + ',':15} {product[0]} }},\n")
        f.write("    { -1, -1 },\n")
        f.write("};\n\n")

        f.write("s8 SingleRecipesWithoutCookbook[] = {\n")
        for recipe in single_recipes:
            f.write(f"    {product_idx[recipe[1]]:-2}, // {recipe[0]:20} --> {recipe[1]}\n")
        f.write("};\n\n")

        f.write("s8 SingleRecipesWithCookbook[] = {\n")
        for recipe in single_recipes:
            if len(recipe) == 3:
                f.write(f"    {product_idx[recipe[2]]:-2}, // {recipe[0]:20} --> {recipe[2]}\n")
            else:
                f.write(f"    {product_idx[recipe[1]]:-2}, // {recipe[0]:20} --> {recipe[1]}\n")
        f.write("};\n\n")

        recipe_map: Dict[int, DoubleRecipe] = {}
        recipe_list: List[DoubleRecipe] = []

        def combine_ids(i, j):
            return i * dim + j

        for entry in double_recipes:
            r = DoubleRecipe(entry, input_idx)
            if r.i < 99999 and r.j < 99999:
                id_pair = combine_ids(r.i, r.j)
                if id_pair in recipe_map:
                    raise Exception(f"Duplicate recipe for {r.in1} and {r.in2} in DoubleRecipes")
                recipe_map[id_pair] = r
            recipe_list.append(r)

        f.write("s8 DoubleRecipesMatrix[] = {\n")
        for i in range(0, dim):
            f.write("   ")
            for j in range(0, dim):
                if j < i:
                    # ignore lower diagonal
                    id = -1
                elif combine_ids(i, j) in recipe_map:
                    # recipe is defined, get product id
                    recipe = recipe_map[combine_ids(i, j)]
                    # this special combination COULD be defined in the matrix, but isn't in vanilla
                    # so we need to grant it a special exception, forcing it to generate in ExtraDoubleRecipes
                    if recipe.in1 == "ITEM_STRANGE_LEAF" and recipe.in2 == "ITEM_WHACKAS_BUMP":
                        id = 0
                    else:
                        id = product_idx[recipe.result]
                        recipe.used = True
                else:
                    # no recipe for this (i,j) -> default to ITEM_MISTAKE
                    id = 0
                f.write(f" {id:-2},")
            f.write("\n")
        f.write("};\n\n")

        f.write("ExtraCookingPair ExtraDoubleRecipes[] = {\n")
        #    for entry in extra_recipes:
        #        f.write(f"    {{ {entry[0]}, {entry[1]}, {product_idx[entry[2]]} }},\n")
        for entry in recipe_list:
            if not entry.used:
                f.write(f"    {{ {entry.in1}, {entry.in2}, {product_idx[entry.result]} }},\n")
        f.write("};\n\n")

        f.write("s32 MysteryResultOptions[] = {\n")
        for product in mystery_products:
            f.write(f"    {product},\n")
        f.write("};\n\n")

        f.write("const s32 CookableItemIDs[] = {\n")
        for rec in records:
            f.write(f"    {rec[0]},\n")
        f.write("};\n\n")

        f.write("const s32 CookableDiscoveredFlags[] = {\n")
        for rec in records:
            f.write(f"    {rec[1]},\n")
        f.write("};\n\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates Tayce T cooking data")
    parser.add_argument("in_yaml", type=Path, help="input yaml file path")
    parser.add_argument("out", help="output file to generate")
    args = parser.parse_args()

    generate(args.in_yaml, args.out)
