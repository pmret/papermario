.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F4C6C
/* 8E11C 800F4C6C 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8E120 800F4C70 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8E124 800F4C74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8E128 800F4C78 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8E12C 800F4C7C AFB00010 */  sw        $s0, 0x10($sp)
/* 8E130 800F4C80 8C430318 */  lw        $v1, 0x318($v0)
/* 8E134 800F4C84 24020003 */  addiu     $v0, $zero, 3
/* 8E138 800F4C88 10620005 */  beq       $v1, $v0, .L800F4CA0
/* 8E13C 800F4C8C 24020005 */   addiu    $v0, $zero, 5
/* 8E140 800F4C90 10620008 */  beq       $v1, $v0, .L800F4CB4
/* 8E144 800F4C94 24A50011 */   addiu    $a1, $a1, 0x11
/* 8E148 800F4C98 0803D338 */  j         .L800F4CE0
/* 8E14C 800F4C9C 00000000 */   nop
.L800F4CA0:
/* 8E150 800F4CA0 24A50010 */  addiu     $a1, $a1, 0x10
/* 8E154 800F4CA4 3C108011 */  lui       $s0, %hi(D_8010D660)
/* 8E158 800F4CA8 8E10D660 */  lw        $s0, %lo(D_8010D660)($s0)
/* 8E15C 800F4CAC 0803D330 */  j         .L800F4CC0
/* 8E160 800F4CB0 24C60010 */   addiu    $a2, $a2, 0x10
.L800F4CB4:
/* 8E164 800F4CB4 3C108011 */  lui       $s0, %hi(D_8010D660)
/* 8E168 800F4CB8 8E10D660 */  lw        $s0, %lo(D_8010D660)($s0)
/* 8E16C 800F4CBC 24C60011 */  addiu     $a2, $a2, 0x11
.L800F4CC0:
/* 8E170 800F4CC0 0C051261 */  jal       set_hud_element_render_pos
/* 8E174 800F4CC4 0200202D */   daddu    $a0, $s0, $zero
/* 8E178 800F4CC8 3C058011 */  lui       $a1, %hi(D_8010D650)
/* 8E17C 800F4CCC 8CA5D650 */  lw        $a1, %lo(D_8010D650)($a1)
/* 8E180 800F4CD0 0C0513AC */  jal       set_hud_element_alpha
/* 8E184 800F4CD4 0200202D */   daddu    $a0, $s0, $zero
/* 8E188 800F4CD8 0C0511EA */  jal       draw_hud_element_clipped
/* 8E18C 800F4CDC 0200202D */   daddu    $a0, $s0, $zero
.L800F4CE0:
/* 8E190 800F4CE0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8E194 800F4CE4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8E198 800F4CE8 03E00008 */  jr        $ra
/* 8E19C 800F4CEC 27BD0018 */   addiu    $sp, $sp, 0x18
