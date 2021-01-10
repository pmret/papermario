.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A94A4_425A34
/* 425A34 802A94A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 425A38 802A94A8 3C03802A */  lui       $v1, %hi(D_8029FBE0)
/* 425A3C 802A94AC 2463FBE0 */  addiu     $v1, $v1, %lo(D_8029FBE0)
/* 425A40 802A94B0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 425A44 802A94B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 425A48 802A94B8 AFB00018 */  sw        $s0, 0x18($sp)
/* 425A4C 802A94BC 8462006A */  lh        $v0, 0x6a($v1)
/* 425A50 802A94C0 14400004 */  bnez      $v0, .L802A94D4
/* 425A54 802A94C4 0060882D */   daddu    $s1, $v1, $zero
/* 425A58 802A94C8 8C640004 */  lw        $a0, 4($v1)
/* 425A5C 802A94CC 0C0511EA */  jal       draw_icon_0
/* 425A60 802A94D0 00000000 */   nop      
.L802A94D4:
/* 425A64 802A94D4 8E300008 */  lw        $s0, 8($s1)
/* 425A68 802A94D8 0C0511EA */  jal       draw_icon_0
/* 425A6C 802A94DC 0200202D */   daddu    $a0, $s0, $zero
/* 425A70 802A94E0 0200202D */  daddu     $a0, $s0, $zero
/* 425A74 802A94E4 27A50010 */  addiu     $a1, $sp, 0x10
/* 425A78 802A94E8 0C05126B */  jal       get_icon_render_pos
/* 425A7C 802A94EC 27A60014 */   addiu    $a2, $sp, 0x14
/* 425A80 802A94F0 3C0451EB */  lui       $a0, 0x51eb
/* 425A84 802A94F4 96230044 */  lhu       $v1, 0x44($s1)
/* 425A88 802A94F8 3484851F */  ori       $a0, $a0, 0x851f
/* 425A8C 802A94FC 00031C00 */  sll       $v1, $v1, 0x10
/* 425A90 802A9500 00031403 */  sra       $v0, $v1, 0x10
/* 425A94 802A9504 00440018 */  mult      $v0, $a0
/* 425A98 802A9508 24070002 */  addiu     $a3, $zero, 2
/* 425A9C 802A950C 8FA50014 */  lw        $a1, 0x14($sp)
/* 425AA0 802A9510 00031FC3 */  sra       $v1, $v1, 0x1f
/* 425AA4 802A9514 8FA40010 */  lw        $a0, 0x10($sp)
/* 425AA8 802A9518 00004010 */  mfhi      $t0
/* 425AAC 802A951C 00083143 */  sra       $a2, $t0, 5
/* 425AB0 802A9520 00C33023 */  subu      $a2, $a2, $v1
/* 425AB4 802A9524 00063400 */  sll       $a2, $a2, 0x10
/* 425AB8 802A9528 0C09A1E6 */  jal       func_80268798
/* 425ABC 802A952C 00063403 */   sra      $a2, $a2, 0x10
/* 425AC0 802A9530 8FBF0020 */  lw        $ra, 0x20($sp)
/* 425AC4 802A9534 8FB1001C */  lw        $s1, 0x1c($sp)
/* 425AC8 802A9538 8FB00018 */  lw        $s0, 0x18($sp)
/* 425ACC 802A953C 03E00008 */  jr        $ra
/* 425AD0 802A9540 27BD0028 */   addiu    $sp, $sp, 0x28
