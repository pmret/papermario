# geo layout macros

# 0x00: Branch and store return address
#   0x04: scriptTarget, segment address of geo layout
.macro geo_branch_and_link scriptTarget
    .byte 0x00, 0x00, 0x00, 0x00
    .word \scriptTarget
.endm

# 0x01: Terminate geo layout
#   0x01-0x03: unused
.macro geo_end
    .byte 0x01, 0x00, 0x00, 0x00
.endm

# 0x02: Branch
#   0x01: if 1, store next geo layout address on stack
#   0x02-0x03: unused
#   0x04: scriptTarget, segment address of geo layout
.macro geo_branch type, scriptTarget
    .byte 0x02, \type, 0x00, 0x00
    .word \scriptTarget
.endm

# 0x03: Return from branch
#   0x01-0x03: unused
.macro geo_return
    .byte 0x03, 0x00, 0x00, 0x00
.endm

# 0x04: Open node
#   0x01-0x03: unused
.macro geo_open_node
    .byte 0x04, 0x00, 0x00, 0x00
.endm

# 0x05: Close node
#   0x01-0x03: unused
.macro geo_close_node
    .byte 0x05, 0x00, 0x00, 0x00
.endm

# 0x06: TODO
#   0x01: unused
#   0x02: s16, index of some array
.macro geo_todo_06 param
    .byte 0x06, 0x00
    .hword \param
.endm

# 0x07: Update current scene graph node flags
#   0x01: u8 operation (0 = reset, 1 = set, 2 = clear)
#   0x02: s16 bits
.macro geo_update_node_flags operation, flagBits
    .byte 0x07, \operation
    .hword \flagBits
.endm

# 0x08: Create screen area scene graph node
#   0x01: unused
#   0x02: s16 num entries (+2) to allocate
#   0x04: s16 x
#   0x06: s16 y
#   0x08: s16 width
#   0x0A: s16 height
.macro geo_node_screen_area numEntries, x, y, width, height
    .byte 0x08, 0x00
    .hword \numEntries
    .hword \x, \y, \width, \height
.endm

# 0x09: TODO Create ? scene graph node
#   0x02: s16 ?
.macro geo_todo_09 param
    .byte 0x09, 0x00
    .hword \param
.endm

# 0x0A: Create camera frustum scene graph node
#   0x01: u8  if nonzero, enable function field
#   0x02: s16 field of view
#   0x04: s16 near
#   0x06: s16 far
#   0x08: [GraphNodeFunc function]
.macro geo_camera_frustum fov, near, far, function=0
    .byte 0x0A
    .if (\function != 0)
       .byte 0x01
    .else
       .byte 0x00
    .endif
    .hword \fov, \near, \far
    .if (\function != 0)
       .word \function
    .endif
.endm

# 0x0B: Create a root scene graph node
#   0x01-0x03: unused
.macro geo_node_start
    .byte 0x0B, 0x00, 0x00, 0x00
.endm

# 0x0C: Create zbuffer-toggling scene graph node
#   0x01: u8 enableZBuffer (1 = on, 0 = off)
#   0x02-0x03: unused
.macro geo_zbuffer enable
    .byte 0x0C, \enable, 0x00, 0x00
.endm

# 0x0D: Create render range scene graph node
#   0x01-0x03: unused
#   0x04: s16 minDistance
#   0x06: s16 maxDistance
.macro geo_render_range minDistance, maxDistance
    .byte 0x0D, 0x00, 0x00, 0x00
    .hword \minDistance, \maxDistance
.endm

# 0x0E: Create switch-case scene graph node
#   0x01: unused
#   0x02: s16 numCases
#   0x04: GraphNodeFunc caseSelectorFunc
.macro geo_switch_case count, function
    .byte 0x0E, 0x00
    .hword \count
    .word \function
.endm

# 0x0F: TODO Create ? scene graph node
#   0x01: unused
#   0x02: s16 ?
#   0x04: s16 unkX
#   0x06: s16 unkY
#   0x08: s16 unkZ
#   0x0A: s16 unkX_2
#   0x0C: s16 unkY_2
#   0x0E: s16 unkZ_2
#   0x10: GraphNodeFunc function
.macro geo_todo_0F unknown, x1, y1, z1, x2, y2, z2, function
    .byte 0x0F, 0x00
    .hword \unknown, \x1, \y1, \z1, \x2, \y2, \z2
    .word \function
.endm

# 0x10: Create translation & rotation scene graph node with optional display list
# Four different versions of 0x10
#   cmd+0x01: u8 params
#     0b1000_0000: if set, enable displayList field and drawingLayer
#     0b0111_0000: fieldLayout (determines how rest of data is formatted
#     0b0000_1111: drawingLayer
#
#   fieldLayout = 0: Translate & Rotate
#     0x04: s16 xTranslation
#     0x06: s16 xTranslation
#     0x08: s16 xTranslation
#     0x0A: s16 xRotation
#     0x0C: s16 xRotation
#     0x0E: s16 xRotation
#     0x10: [u32 displayList: if MSbit of params set, display list segmented address]
.macro geo_translate_rotate layer, tx, ty, tz, rx, ry, rz, displayList=0
    .byte 0x10
    .if (\displayList != 0)
        .byte 0x00 | \layer | 0x80
    .else
        .byte 0x00 | \layer
    .endif
    .hword 0x0000
    .hword \tx, \ty, \tz
    .hword \rx, \ry, \rz
    .if (\displayList != 0)
        .word \displayList
    .endif
.endm

#   fieldLayout = 1: Translate
#     0x02: s16 xTranslation
#     0x04: s16 yTranslation
#     0x06: s16 zTranslation
#     0x08: [u32 displayList: if MSbit of params set, display list segmented address]
.macro geo_translate layer, tx, ty, tz, displayList=0
    .byte 0x10
    .if (\displayList != 0)
        .byte 0x10 | \layer | 0x80
    .else
        .byte 0x10 | \layer
    .endif
    .hword \tx, \ty, \tz
    .if (\displayList != 0)
        .word \displayList
    .endif
.endm

#   fieldLayout = 2: Rotate
#     0x02: s16 xRotation
#     0x04: s16 yRotation
#     0x06: s16 zRotation
#     0x08: [u32 displayList: if MSbit of params set, display list segmented address]
.macro geo_rotate layer, rx, ry, rz, displayList=0
    .byte 0x10
    .if (\displayList != 0)
        .byte 0x20 | \layer | 0x80
    .else
        .byte 0x20 | \layer
    .endif
    .hword \rx, \ry, \rz
    .if (\displayList != 0)
        .word \displayList
    .endif
.endm

#   fieldLayout = 3: Rotate Y
#     0x02: s16 yRotation
#     0x04: [u32 displayList: if MSbit of params set, display list segmented address]
.macro geo_rotate_y layer, ry, displayList=0
    .byte 0x10
    .if (\displayList != 0)
        .byte 0x30 | \layer | 0x80
    .else
        .byte 0x30 | \layer
    .endif
    .hword \ry
    .if (\displayList != 0)
        .word \displayList
    .endif
.endm

# 0x11: TODO Create ? scene graph node with optional display list
#   0x01: u8 params
#     0b1000_0000: if set, enable displayList field and drawingLayer
#     0b0000_1111: drawingLayer
#   0x02: s16 unkX
#   0x04: s16 unkY
#   0x06: s16 unkZ
#   0x08: [u32 displayList: if MSbit of params set, display list segmented address]
.macro geo_todo_11 layer, ux, uy, uz, displayList=0
    .byte 0x11
    .if (\displayList != 0)
        .byte 0x80 | \layer
    .else
        .byte 0x00
    .endif
    .hword \ux, \uy, \uz
    .if (\displayList != 0)
        .word \displayList
    .endif
.endm

# 0x12: TODO Create ? scene graph node
#   0x01: u8 params
#      0b1000_0000: if set, enable displayList field and drawingLayer
#      0b0000_1111: drawingLayer
#   0x02: s16 unkX
#   0x04: s16 unkY
#   0x06: s16 unkZ
#   0x08: [u32 displayList: if MSbit of params set, display list segmented address]
.macro geo_todo_12 layer, ux, uy, uz, displayList=0
    .byte 0x12
    .if (\displayList != 0)
        .byte 0x80 | \layer
    .else
        .byte 0x00
    .endif
    .hword \ux, \uy, \uz
    .if (\displayList != 0)
        .word \displayList
    .endif
.endm

# 0x13: Create display list scene graph node with translation
#   0x01: u8 drawingLayer
#   0x02: s16 xTranslation
#   0x04: s16 yTranslation
#   0x06: s16 zTranslation
#   0x08: u32 displayList: dislay list segmented address
.macro geo_dl_translated layer, x, y, z, displayList=0
    .byte 0x13, \layer
    .hword \x, \y, \z
    .word \displayList
.endm

# 0x14: Create billboarding node with optional display list
#   0x01: u8 params
#      0b1000_0000: if set, enable displayList field and drawingLayer
#      0b0000_1111: drawingLayer
#   0x02: s16 xTranslation
#   0x04: s16 yTranslation
#   0x06: s16 zTranslation
#   0x08: [u32 displayList: if MSbit of params is set, display list segmented address]
.macro geo_billboard layer=0, tx=0, ty=0, tz=0, displayList=0
    .byte 0x14
    .if (\displayList != 0)
        .byte 0x80 | \layer
    .else
        .byte 0x00
    .endif
    .hword \tx, \ty, \tz
    .if (\displayList != 0)
        .word \displayList
    .endif
.endm

# 0x15: Create plain display list scene graph node
#   0x01: u8 drawingLayer
#   0x02=0x03: unused
#   0x04: u32 displayList: display list segmented address
.macro geo_display_list layer, displayList
    .byte 0x15, \layer, 0x00, 0x00
    .word \displayList
.endm

# 0x16: Create shadow scene graph node
#   0x01: unused
#   0x02: s16 shadowType (cast to u8)
#   0x04: s16 shadowSolidity (cast to u8)
#   0x06: s16 shadowScale
.set SHADOW_CIRCLE_UNK0,      0x00
.set SHADOW_CIRCLE_UNK1,      0x01
.set SHADOW_CIRCLE_UNK2,      0x02  # unused shadow type
.set SHADOW_SQUARE_PERMANENT, 0x0A  # square shadow that never disappears
.set SHADOW_SQUARE_SCALABLE,  0x0B  # square shadow, shrinks with distance
.set SHADOW_SQUARE_TOGGLABLE, 0x0C  # square shadow, disappears with distance
.set SHADOW_CIRCLE_PLAYER,    0x63  # player (Mario) shadow
.set SHADOW_RECTANGLE_HARDCODED_OFFSET, 0x32 # offset of hard-coded shadows
.macro geo_shadow type, solidity, scale
    .byte 0x16, 0x00
    .hword \type, \solidity, \scale
.endm

# 0x17: TODO Create ? scene graph node
#   0x01-0x03: unused
.macro geo_todo_17
    .byte 0x17, 0x00, 0x00, 0x00
.endm

# 0x18: Create ? scene graph node
#   0x01: unused
#   0x02: s16 parameter
#   0x04: GraphNodeFunc function
.macro geo_asm param, function
    .byte 0x18, 0x00
    .hword \param
    .word \function
.endm

# 0x19: Create background scene graph node
#   0x02: s16 background: background ID, or RGBA5551 color if backgroundFunc is null
#   0x04: GraphNodeFunc backgroundFunc
.macro geo_background param, function=0
    .byte 0x19, 0x00
    .hword \param
    .word \function
.endm

# 0x1A: No operation
.macro geo_nop_1A
    .byte 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.endm

# 0x1B: TODO Create ? scene graph node
#   0x02: s16 index of array
.macro geo_todo_1B param
    .byte 0x1B, 0x00
    .hword \param
.endm

# 0x1C: TODO Create ? scene graph node
#   0x01: u8 unk01
#   0x02: s16 unkX
#   0x04: s16 unkY
#   0x06: s16 unkZ
#   0x08: GraphNodeFunc nodeFunc
.macro geo_todo_1C param, ux, uy, uz, nodeFunc
    .byte 0x1C, \param
    .hword \ux, \uy, \uz
    .word \nodeFunc
.endm

# 0x1D: Create scale scene graph node with optional display list
#   0x01: u8 params
#     0b1000_0000: if set, enable displayList field and drawingLayer
#     0b0000_1111: drawingLayer
#   0x02-0x03: unused
#   0x04: u32 scale (0x10000 = 1.0)
#   0x08: [u32 displayList: if MSbit of params is set, display list segment address]
.macro geo_scale layer, scale, displayList=0
    .byte 0x1D
    .if (\displayList != 0)
        .byte 0x80 | \layer
    .else
        .byte 0x00
    .endif
    .byte 0x00, 0x00
    .word \scale
    .if (\displayList != 0)
        .word \displayList
    .endif
.endm

# 0x1E: No operation
.macro geo_nop_1E
    .byte 0x1E, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00
.endm

# 0x1F: No operation
.macro geo_nop_1F
    .byte 0x1F, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00
.endm

# 0x20: Create render distance scene graph node (unconfirmed?)
#   0x01: unused
#   0x02: s16 renderDistance?
.macro geo_start_distance renderDistance
    .byte 0x20, 0x00
    .hword \renderDistance
.endm

