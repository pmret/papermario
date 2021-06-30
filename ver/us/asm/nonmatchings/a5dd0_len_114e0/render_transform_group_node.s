.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_transform_group_node
/* AE574 80117E74 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AE578 80117E78 AFB20018 */  sw        $s2, 0x18($sp)
/* AE57C 80117E7C 0080902D */  daddu     $s2, $a0, $zero
/* AE580 80117E80 AFB3001C */  sw        $s3, 0x1c($sp)
/* AE584 80117E84 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* AE588 80117E88 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* AE58C 80117E8C AFBF0020 */  sw        $ra, 0x20($sp)
/* AE590 80117E90 AFB10014 */  sw        $s1, 0x14($sp)
/* AE594 80117E94 12400056 */  beqz      $s2, .L80117FF0
/* AE598 80117E98 AFB00010 */   sw       $s0, 0x10($sp)
/* AE59C 80117E9C 8E430000 */  lw        $v1, ($s2)
/* AE5A0 80117EA0 24020005 */  addiu     $v0, $zero, 5
/* AE5A4 80117EA4 14620017 */  bne       $v1, $v0, .L80117F04
/* AE5A8 80117EA8 24020002 */   addiu    $v0, $zero, 2
/* AE5AC 80117EAC 0C0456C3 */  jal       get_model_property
/* AE5B0 80117EB0 24050060 */   addiu    $a1, $zero, 0x60
/* AE5B4 80117EB4 10400011 */  beqz      $v0, .L80117EFC
/* AE5B8 80117EB8 00000000 */   nop
/* AE5BC 80117EBC 8C420008 */  lw        $v0, 8($v0)
/* AE5C0 80117EC0 1040000E */  beqz      $v0, .L80117EFC
/* AE5C4 80117EC4 00000000 */   nop
/* AE5C8 80117EC8 3C108015 */  lui       $s0, %hi(D_8015336C)
/* AE5CC 80117ECC 2610336C */  addiu     $s0, $s0, %lo(D_8015336C)
/* AE5D0 80117ED0 0C046B4C */  jal       get_model_from_list_index
/* AE5D4 80117ED4 96040000 */   lhu      $a0, ($s0)
/* AE5D8 80117ED8 0040202D */  daddu     $a0, $v0, $zero
/* AE5DC 80117EDC 94820000 */  lhu       $v0, ($a0)
/* AE5E0 80117EE0 30420002 */  andi      $v0, $v0, 2
/* AE5E4 80117EE4 1440003F */  bnez      $v0, .L80117FE4
/* AE5E8 80117EE8 00000000 */   nop
/* AE5EC 80117EEC 0C045F25 */  jal       appendGfx_model_group
/* AE5F0 80117EF0 00000000 */   nop
/* AE5F4 80117EF4 08045FF9 */  j         .L80117FE4
/* AE5F8 80117EF8 00000000 */   nop
.L80117EFC:
/* AE5FC 80117EFC 8E430000 */  lw        $v1, ($s2)
/* AE600 80117F00 24020002 */  addiu     $v0, $zero, 2
.L80117F04:
/* AE604 80117F04 1062002C */  beq       $v1, $v0, .L80117FB8
/* AE608 80117F08 00000000 */   nop
/* AE60C 80117F0C 8E420010 */  lw        $v0, 0x10($s2)
/* AE610 80117F10 10400037 */  beqz      $v0, .L80117FF0
/* AE614 80117F14 00000000 */   nop
/* AE618 80117F18 8C420000 */  lw        $v0, ($v0)
/* AE61C 80117F1C 10400009 */  beqz      $v0, .L80117F44
/* AE620 80117F20 3C02DA38 */   lui      $v0, 0xda38
/* AE624 80117F24 8E630000 */  lw        $v1, ($s3)
/* AE628 80117F28 0060202D */  daddu     $a0, $v1, $zero
/* AE62C 80117F2C AC820000 */  sw        $v0, ($a0)
/* AE630 80117F30 8E420010 */  lw        $v0, 0x10($s2)
/* AE634 80117F34 8C420000 */  lw        $v0, ($v0)
/* AE638 80117F38 24630008 */  addiu     $v1, $v1, 8
/* AE63C 80117F3C AE630000 */  sw        $v1, ($s3)
/* AE640 80117F40 AC820004 */  sw        $v0, 4($a0)
.L80117F44:
/* AE644 80117F44 8E420010 */  lw        $v0, 0x10($s2)
/* AE648 80117F48 8C51000C */  lw        $s1, 0xc($v0)
/* AE64C 80117F4C 1220000E */  beqz      $s1, .L80117F88
/* AE650 80117F50 00000000 */   nop
/* AE654 80117F54 1A20000C */  blez      $s1, .L80117F88
/* AE658 80117F58 0000802D */   daddu    $s0, $zero, $zero
.L80117F5C:
/* AE65C 80117F5C 8E420010 */  lw        $v0, 0x10($s2)
/* AE660 80117F60 8C430010 */  lw        $v1, 0x10($v0)
/* AE664 80117F64 00101080 */  sll       $v0, $s0, 2
/* AE668 80117F68 00431021 */  addu      $v0, $v0, $v1
/* AE66C 80117F6C 8C440000 */  lw        $a0, ($v0)
/* AE670 80117F70 0C045F9D */  jal       render_transform_group_node
/* AE674 80117F74 26100001 */   addiu    $s0, $s0, 1
/* AE678 80117F78 0211102A */  slt       $v0, $s0, $s1
/* AE67C 80117F7C 1440FFF7 */  bnez      $v0, .L80117F5C
/* AE680 80117F80 00000000 */   nop
/* AE684 80117F84 8E420010 */  lw        $v0, 0x10($s2)
.L80117F88:
/* AE688 80117F88 8C420000 */  lw        $v0, ($v0)
/* AE68C 80117F8C 10400018 */  beqz      $v0, .L80117FF0
/* AE690 80117F90 3C04D838 */   lui      $a0, 0xd838
/* AE694 80117F94 8E620000 */  lw        $v0, ($s3)
/* AE698 80117F98 34840002 */  ori       $a0, $a0, 2
/* AE69C 80117F9C 0040182D */  daddu     $v1, $v0, $zero
/* AE6A0 80117FA0 24420008 */  addiu     $v0, $v0, 8
/* AE6A4 80117FA4 AE620000 */  sw        $v0, ($s3)
/* AE6A8 80117FA8 24020040 */  addiu     $v0, $zero, 0x40
/* AE6AC 80117FAC AC640000 */  sw        $a0, ($v1)
/* AE6B0 80117FB0 08045FFC */  j         .L80117FF0
/* AE6B4 80117FB4 AC620004 */   sw       $v0, 4($v1)
.L80117FB8:
/* AE6B8 80117FB8 3C108015 */  lui       $s0, %hi(D_8015336C)
/* AE6BC 80117FBC 2610336C */  addiu     $s0, $s0, %lo(D_8015336C)
/* AE6C0 80117FC0 0C046B4C */  jal       get_model_from_list_index
/* AE6C4 80117FC4 96040000 */   lhu      $a0, ($s0)
/* AE6C8 80117FC8 0040202D */  daddu     $a0, $v0, $zero
/* AE6CC 80117FCC 94820000 */  lhu       $v0, ($a0)
/* AE6D0 80117FD0 30420002 */  andi      $v0, $v0, 2
/* AE6D4 80117FD4 14400003 */  bnez      $v0, .L80117FE4
/* AE6D8 80117FD8 00000000 */   nop
/* AE6DC 80117FDC 0C044C24 */  jal       appendGfx_model
/* AE6E0 80117FE0 00000000 */   nop
.L80117FE4:
/* AE6E4 80117FE4 96020000 */  lhu       $v0, ($s0)
/* AE6E8 80117FE8 24420001 */  addiu     $v0, $v0, 1
/* AE6EC 80117FEC A6020000 */  sh        $v0, ($s0)
.L80117FF0:
/* AE6F0 80117FF0 8FBF0020 */  lw        $ra, 0x20($sp)
/* AE6F4 80117FF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* AE6F8 80117FF8 8FB20018 */  lw        $s2, 0x18($sp)
/* AE6FC 80117FFC 8FB10014 */  lw        $s1, 0x14($sp)
/* AE700 80118000 8FB00010 */  lw        $s0, 0x10($sp)
/* AE704 80118004 03E00008 */  jr        $ra
/* AE708 80118008 27BD0028 */   addiu    $sp, $sp, 0x28
