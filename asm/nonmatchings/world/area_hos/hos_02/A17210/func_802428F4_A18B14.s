.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428F4_A18B14
/* A18B14 802428F4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A18B18 802428F8 AFB40040 */  sw        $s4, 0x40($sp)
/* A18B1C 802428FC 0080A02D */  daddu     $s4, $a0, $zero
/* A18B20 80242900 AFBF0048 */  sw        $ra, 0x48($sp)
/* A18B24 80242904 AFB50044 */  sw        $s5, 0x44($sp)
/* A18B28 80242908 AFB3003C */  sw        $s3, 0x3c($sp)
/* A18B2C 8024290C AFB20038 */  sw        $s2, 0x38($sp)
/* A18B30 80242910 AFB10034 */  sw        $s1, 0x34($sp)
/* A18B34 80242914 AFB00030 */  sw        $s0, 0x30($sp)
/* A18B38 80242918 8E920148 */  lw        $s2, 0x148($s4)
/* A18B3C 8024291C 86440008 */  lh        $a0, 8($s2)
/* A18B40 80242920 8E90000C */  lw        $s0, 0xc($s4)
/* A18B44 80242924 0C00EABB */  jal       get_npc_unsafe
/* A18B48 80242928 00A0882D */   daddu    $s1, $a1, $zero
/* A18B4C 8024292C 0280202D */  daddu     $a0, $s4, $zero
/* A18B50 80242930 8E050000 */  lw        $a1, ($s0)
/* A18B54 80242934 0C0B1EAF */  jal       get_variable
/* A18B58 80242938 0040A82D */   daddu    $s5, $v0, $zero
/* A18B5C 8024293C AFA00010 */  sw        $zero, 0x10($sp)
/* A18B60 80242940 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A18B64 80242944 8C630030 */  lw        $v1, 0x30($v1)
/* A18B68 80242948 AFA30014 */  sw        $v1, 0x14($sp)
/* A18B6C 8024294C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A18B70 80242950 8C63001C */  lw        $v1, 0x1c($v1)
/* A18B74 80242954 AFA30018 */  sw        $v1, 0x18($sp)
/* A18B78 80242958 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A18B7C 8024295C 8C630024 */  lw        $v1, 0x24($v1)
/* A18B80 80242960 AFA3001C */  sw        $v1, 0x1c($sp)
/* A18B84 80242964 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A18B88 80242968 8C630028 */  lw        $v1, 0x28($v1)
/* A18B8C 8024296C 27B30010 */  addiu     $s3, $sp, 0x10
/* A18B90 80242970 AFA30020 */  sw        $v1, 0x20($sp)
/* A18B94 80242974 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A18B98 80242978 3C0142F0 */  lui       $at, 0x42f0
/* A18B9C 8024297C 44810000 */  mtc1      $at, $f0
/* A18BA0 80242980 8C63002C */  lw        $v1, 0x2c($v1)
/* A18BA4 80242984 0040802D */  daddu     $s0, $v0, $zero
/* A18BA8 80242988 E7A00028 */  swc1      $f0, 0x28($sp)
/* A18BAC 8024298C A7A0002C */  sh        $zero, 0x2c($sp)
/* A18BB0 80242990 12200007 */  beqz      $s1, .L802429B0
/* A18BB4 80242994 AFA30024 */   sw       $v1, 0x24($sp)
/* A18BB8 80242998 02A0202D */  daddu     $a0, $s5, $zero
/* A18BBC 8024299C 0240282D */  daddu     $a1, $s2, $zero
/* A18BC0 802429A0 0280302D */  daddu     $a2, $s4, $zero
/* A18BC4 802429A4 0C090876 */  jal       func_802421D8_A183F8
/* A18BC8 802429A8 0200382D */   daddu    $a3, $s0, $zero
/* A18BCC 802429AC AE800070 */  sw        $zero, 0x70($s4)
.L802429B0:
/* A18BD0 802429B0 2402FFFE */  addiu     $v0, $zero, -2
/* A18BD4 802429B4 A2A200AB */  sb        $v0, 0xab($s5)
/* A18BD8 802429B8 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A18BDC 802429BC 30620004 */  andi      $v0, $v1, 4
/* A18BE0 802429C0 10400007 */  beqz      $v0, .L802429E0
/* A18BE4 802429C4 00000000 */   nop      
/* A18BE8 802429C8 824200B4 */  lb        $v0, 0xb4($s2)
/* A18BEC 802429CC 1440003A */  bnez      $v0, .L80242AB8
/* A18BF0 802429D0 0000102D */   daddu    $v0, $zero, $zero
/* A18BF4 802429D4 2402FFFB */  addiu     $v0, $zero, -5
/* A18BF8 802429D8 00621024 */  and       $v0, $v1, $v0
/* A18BFC 802429DC AE4200B0 */  sw        $v0, 0xb0($s2)
.L802429E0:
/* A18C00 802429E0 8E830070 */  lw        $v1, 0x70($s4)
/* A18C04 802429E4 2C620015 */  sltiu     $v0, $v1, 0x15
/* A18C08 802429E8 10400032 */  beqz      $v0, .L80242AB4
/* A18C0C 802429EC 00031080 */   sll      $v0, $v1, 2
/* A18C10 802429F0 3C018024 */  lui       $at, 0x8024
/* A18C14 802429F4 00220821 */  addu      $at, $at, $v0
/* A18C18 802429F8 8C224E80 */  lw        $v0, 0x4e80($at)
/* A18C1C 802429FC 00400008 */  jr        $v0
/* A18C20 80242A00 00000000 */   nop      
/* A18C24 80242A04 0280202D */  daddu     $a0, $s4, $zero
/* A18C28 80242A08 0200282D */  daddu     $a1, $s0, $zero
/* A18C2C 80242A0C 0C0903FC */  jal       func_80240FF0_A17210
/* A18C30 80242A10 0260302D */   daddu    $a2, $s3, $zero
/* A18C34 80242A14 0280202D */  daddu     $a0, $s4, $zero
/* A18C38 80242A18 0200282D */  daddu     $a1, $s0, $zero
/* A18C3C 80242A1C 0C090468 */  jal       func_802411A0_A173C0
/* A18C40 80242A20 0260302D */   daddu    $a2, $s3, $zero
/* A18C44 80242A24 08090AAE */  j         .L80242AB8
/* A18C48 80242A28 0000102D */   daddu    $v0, $zero, $zero
/* A18C4C 80242A2C 0280202D */  daddu     $a0, $s4, $zero
/* A18C50 80242A30 0200282D */  daddu     $a1, $s0, $zero
/* A18C54 80242A34 0C0905F2 */  jal       func_802417C8_A179E8
/* A18C58 80242A38 0260302D */   daddu    $a2, $s3, $zero
/* A18C5C 80242A3C 0280202D */  daddu     $a0, $s4, $zero
/* A18C60 80242A40 0200282D */  daddu     $a1, $s0, $zero
/* A18C64 80242A44 0C090622 */  jal       func_80241888_A17AA8
/* A18C68 80242A48 0260302D */   daddu    $a2, $s3, $zero
/* A18C6C 80242A4C 08090AAE */  j         .L80242AB8
/* A18C70 80242A50 0000102D */   daddu    $v0, $zero, $zero
/* A18C74 80242A54 0280202D */  daddu     $a0, $s4, $zero
/* A18C78 80242A58 0200282D */  daddu     $a1, $s0, $zero
/* A18C7C 80242A5C 0C0906F3 */  jal       func_80241BCC_A17DEC
/* A18C80 80242A60 0260302D */   daddu    $a2, $s3, $zero
/* A18C84 80242A64 0280202D */  daddu     $a0, $s4, $zero
/* A18C88 80242A68 0200282D */  daddu     $a1, $s0, $zero
/* A18C8C 80242A6C 0C090711 */  jal       func_80241C44_A17E64
/* A18C90 80242A70 0260302D */   daddu    $a2, $s3, $zero
/* A18C94 80242A74 08090AAE */  j         .L80242AB8
/* A18C98 80242A78 0000102D */   daddu    $v0, $zero, $zero
/* A18C9C 80242A7C 0280202D */  daddu     $a0, $s4, $zero
/* A18CA0 80242A80 0200282D */  daddu     $a1, $s0, $zero
/* A18CA4 80242A84 0C09093A */  jal       func_802424E8_A18708
/* A18CA8 80242A88 0260302D */   daddu    $a2, $s3, $zero
/* A18CAC 80242A8C 0280202D */  daddu     $a0, $s4, $zero
/* A18CB0 80242A90 0200282D */  daddu     $a1, $s0, $zero
/* A18CB4 80242A94 0C090986 */  jal       func_80242618_A18838
/* A18CB8 80242A98 0260302D */   daddu    $a2, $s3, $zero
/* A18CBC 80242A9C 08090AAE */  j         .L80242AB8
/* A18CC0 80242AA0 0000102D */   daddu    $v0, $zero, $zero
/* A18CC4 80242AA4 0280202D */  daddu     $a0, $s4, $zero
/* A18CC8 80242AA8 0200282D */  daddu     $a1, $s0, $zero
/* A18CCC 80242AAC 0C090A26 */  jal       func_80242898_A18AB8
/* A18CD0 80242AB0 0260302D */   daddu    $a2, $s3, $zero
.L80242AB4:
/* A18CD4 80242AB4 0000102D */  daddu     $v0, $zero, $zero
.L80242AB8:
/* A18CD8 80242AB8 8FBF0048 */  lw        $ra, 0x48($sp)
/* A18CDC 80242ABC 8FB50044 */  lw        $s5, 0x44($sp)
/* A18CE0 80242AC0 8FB40040 */  lw        $s4, 0x40($sp)
/* A18CE4 80242AC4 8FB3003C */  lw        $s3, 0x3c($sp)
/* A18CE8 80242AC8 8FB20038 */  lw        $s2, 0x38($sp)
/* A18CEC 80242ACC 8FB10034 */  lw        $s1, 0x34($sp)
/* A18CF0 80242AD0 8FB00030 */  lw        $s0, 0x30($sp)
/* A18CF4 80242AD4 03E00008 */  jr        $ra
/* A18CF8 80242AD8 27BD0050 */   addiu    $sp, $sp, 0x50
/* A18CFC 80242ADC 00000000 */  nop       
