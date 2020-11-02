.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B04_BA7284
/* BA7284 80242B04 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BA7288 80242B08 AFB3003C */  sw        $s3, 0x3c($sp)
/* BA728C 80242B0C 0080982D */  daddu     $s3, $a0, $zero
/* BA7290 80242B10 AFBF0048 */  sw        $ra, 0x48($sp)
/* BA7294 80242B14 AFB50044 */  sw        $s5, 0x44($sp)
/* BA7298 80242B18 AFB40040 */  sw        $s4, 0x40($sp)
/* BA729C 80242B1C AFB20038 */  sw        $s2, 0x38($sp)
/* BA72A0 80242B20 AFB10034 */  sw        $s1, 0x34($sp)
/* BA72A4 80242B24 AFB00030 */  sw        $s0, 0x30($sp)
/* BA72A8 80242B28 8E720148 */  lw        $s2, 0x148($s3)
/* BA72AC 80242B2C 86440008 */  lh        $a0, 8($s2)
/* BA72B0 80242B30 8E70000C */  lw        $s0, 0xc($s3)
/* BA72B4 80242B34 0C00EABB */  jal       get_npc_unsafe
/* BA72B8 80242B38 00A0882D */   daddu    $s1, $a1, $zero
/* BA72BC 80242B3C 8E050000 */  lw        $a1, ($s0)
/* BA72C0 80242B40 26100004 */  addiu     $s0, $s0, 4
/* BA72C4 80242B44 0260202D */  daddu     $a0, $s3, $zero
/* BA72C8 80242B48 0C0B1EAF */  jal       get_variable
/* BA72CC 80242B4C 0040A82D */   daddu    $s5, $v0, $zero
/* BA72D0 80242B50 0260202D */  daddu     $a0, $s3, $zero
/* BA72D4 80242B54 8E050000 */  lw        $a1, ($s0)
/* BA72D8 80242B58 0C0B1EAF */  jal       get_variable
/* BA72DC 80242B5C 0040A02D */   daddu    $s4, $v0, $zero
/* BA72E0 80242B60 AE420094 */  sw        $v0, 0x94($s2)
/* BA72E4 80242B64 AFA00010 */  sw        $zero, 0x10($sp)
/* BA72E8 80242B68 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BA72EC 80242B6C 8C420030 */  lw        $v0, 0x30($v0)
/* BA72F0 80242B70 AFA20014 */  sw        $v0, 0x14($sp)
/* BA72F4 80242B74 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BA72F8 80242B78 8C42001C */  lw        $v0, 0x1c($v0)
/* BA72FC 80242B7C AFA20018 */  sw        $v0, 0x18($sp)
/* BA7300 80242B80 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BA7304 80242B84 8C420024 */  lw        $v0, 0x24($v0)
/* BA7308 80242B88 AFA2001C */  sw        $v0, 0x1c($sp)
/* BA730C 80242B8C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BA7310 80242B90 8C420028 */  lw        $v0, 0x28($v0)
/* BA7314 80242B94 AFA20020 */  sw        $v0, 0x20($sp)
/* BA7318 80242B98 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BA731C 80242B9C 3C0142C8 */  lui       $at, 0x42c8
/* BA7320 80242BA0 44810000 */  mtc1      $at, $f0
/* BA7324 80242BA4 8C42002C */  lw        $v0, 0x2c($v0)
/* BA7328 80242BA8 27B00010 */  addiu     $s0, $sp, 0x10
/* BA732C 80242BAC E7A00028 */  swc1      $f0, 0x28($sp)
/* BA7330 80242BB0 A7A0002C */  sh        $zero, 0x2c($sp)
/* BA7334 80242BB4 12200019 */  beqz      $s1, .L80242C1C
/* BA7338 80242BB8 AFA20024 */   sw       $v0, 0x24($sp)
/* BA733C 80242BBC AE600070 */  sw        $zero, 0x70($s3)
/* BA7340 80242BC0 A6A0008E */  sh        $zero, 0x8e($s5)
/* BA7344 80242BC4 AE600074 */  sw        $zero, 0x74($s3)
/* BA7348 80242BC8 8EA20000 */  lw        $v0, ($s5)
/* BA734C 80242BCC 2403F7FF */  addiu     $v1, $zero, -0x801
/* BA7350 80242BD0 00431024 */  and       $v0, $v0, $v1
/* BA7354 80242BD4 2403FDFF */  addiu     $v1, $zero, -0x201
/* BA7358 80242BD8 00431024 */  and       $v0, $v0, $v1
/* BA735C 80242BDC 34420008 */  ori       $v0, $v0, 8
/* BA7360 80242BE0 AEA20000 */  sw        $v0, ($s5)
/* BA7364 80242BE4 8E4200B0 */  lw        $v0, 0xb0($s2)
/* BA7368 80242BE8 34420018 */  ori       $v0, $v0, 0x18
/* BA736C 80242BEC AE4200B0 */  sw        $v0, 0xb0($s2)
/* BA7370 80242BF0 8E420000 */  lw        $v0, ($s2)
/* BA7374 80242BF4 3C034000 */  lui       $v1, 0x4000
/* BA7378 80242BF8 00431024 */  and       $v0, $v0, $v1
/* BA737C 80242BFC 10400007 */  beqz      $v0, .L80242C1C
/* BA7380 80242C00 3C03BFFF */   lui      $v1, 0xbfff
/* BA7384 80242C04 2402000C */  addiu     $v0, $zero, 0xc
/* BA7388 80242C08 AE620070 */  sw        $v0, 0x70($s3)
/* BA738C 80242C0C 8E420000 */  lw        $v0, ($s2)
/* BA7390 80242C10 3463FFFF */  ori       $v1, $v1, 0xffff
/* BA7394 80242C14 00431024 */  and       $v0, $v0, $v1
/* BA7398 80242C18 AE420000 */  sw        $v0, ($s2)
.L80242C1C:
/* BA739C 80242C1C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BA73A0 80242C20 30620004 */  andi      $v0, $v1, 4
/* BA73A4 80242C24 10400007 */  beqz      $v0, .L80242C44
/* BA73A8 80242C28 00000000 */   nop      
/* BA73AC 80242C2C 824200B4 */  lb        $v0, 0xb4($s2)
/* BA73B0 80242C30 14400034 */  bnez      $v0, .L80242D04
/* BA73B4 80242C34 0000102D */   daddu    $v0, $zero, $zero
/* BA73B8 80242C38 2402FFFB */  addiu     $v0, $zero, -5
/* BA73BC 80242C3C 00621024 */  and       $v0, $v1, $v0
/* BA73C0 80242C40 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242C44:
/* BA73C4 80242C44 8E630070 */  lw        $v1, 0x70($s3)
/* BA73C8 80242C48 2C62000F */  sltiu     $v0, $v1, 0xf
/* BA73CC 80242C4C 1040002C */  beqz      $v0, .L80242D00
/* BA73D0 80242C50 00031080 */   sll      $v0, $v1, 2
/* BA73D4 80242C54 3C018024 */  lui       $at, %hi(pause_stats_draw_contents)
/* BA73D8 80242C58 00220821 */  addu      $at, $at, $v0
/* BA73DC 80242C5C 8C225980 */  lw        $v0, %lo(pause_stats_draw_contents)($at)
/* BA73E0 80242C60 00400008 */  jr        $v0
/* BA73E4 80242C64 00000000 */   nop      
/* BA73E8 80242C68 0260202D */  daddu     $a0, $s3, $zero
/* BA73EC 80242C6C 0280282D */  daddu     $a1, $s4, $zero
/* BA73F0 80242C70 0C0907C5 */  jal       func_80241F14_BA6694
/* BA73F4 80242C74 0200302D */   daddu    $a2, $s0, $zero
/* BA73F8 80242C78 0260202D */  daddu     $a0, $s3, $zero
/* BA73FC 80242C7C 0280282D */  daddu     $a1, $s4, $zero
/* BA7400 80242C80 0C090851 */  jal       func_80242144_BA68C4
/* BA7404 80242C84 0200302D */   daddu    $a2, $s0, $zero
/* BA7408 80242C88 08090B41 */  j         .L80242D04
/* BA740C 80242C8C 0000102D */   daddu    $v0, $zero, $zero
/* BA7410 80242C90 0260202D */  daddu     $a0, $s3, $zero
/* BA7414 80242C94 0280282D */  daddu     $a1, $s4, $zero
/* BA7418 80242C98 0C09091F */  jal       func_8024247C_BA6BFC
/* BA741C 80242C9C 0200302D */   daddu    $a2, $s0, $zero
/* BA7420 80242CA0 8E630070 */  lw        $v1, 0x70($s3)
/* BA7424 80242CA4 24020003 */  addiu     $v0, $zero, 3
/* BA7428 80242CA8 14620016 */  bne       $v1, $v0, .L80242D04
/* BA742C 80242CAC 0000102D */   daddu    $v0, $zero, $zero
/* BA7430 80242CB0 0260202D */  daddu     $a0, $s3, $zero
/* BA7434 80242CB4 0280282D */  daddu     $a1, $s4, $zero
/* BA7438 80242CB8 0C09094F */  jal       func_8024253C_BA6CBC
/* BA743C 80242CBC 0200302D */   daddu    $a2, $s0, $zero
/* BA7440 80242CC0 08090B41 */  j         .L80242D04
/* BA7444 80242CC4 0000102D */   daddu    $v0, $zero, $zero
/* BA7448 80242CC8 0260202D */  daddu     $a0, $s3, $zero
/* BA744C 80242CCC 0280282D */  daddu     $a1, $s4, $zero
/* BA7450 80242CD0 0C0909B8 */  jal       func_802426E0_BA6E60
/* BA7454 80242CD4 0200302D */   daddu    $a2, $s0, $zero
/* BA7458 80242CD8 0260202D */  daddu     $a0, $s3, $zero
/* BA745C 80242CDC 0280282D */  daddu     $a1, $s4, $zero
/* BA7460 80242CE0 0C0909F0 */  jal       func_802427C0_BA6F40
/* BA7464 80242CE4 0200302D */   daddu    $a2, $s0, $zero
/* BA7468 80242CE8 08090B41 */  j         .L80242D04
/* BA746C 80242CEC 0000102D */   daddu    $v0, $zero, $zero
/* BA7470 80242CF0 0260202D */  daddu     $a0, $s3, $zero
/* BA7474 80242CF4 0280282D */  daddu     $a1, $s4, $zero
/* BA7478 80242CF8 0C090AB0 */  jal       func_80242AC0_BA7240
/* BA747C 80242CFC 0200302D */   daddu    $a2, $s0, $zero
.L80242D00:
/* BA7480 80242D00 0000102D */  daddu     $v0, $zero, $zero
.L80242D04:
/* BA7484 80242D04 8FBF0048 */  lw        $ra, 0x48($sp)
/* BA7488 80242D08 8FB50044 */  lw        $s5, 0x44($sp)
/* BA748C 80242D0C 8FB40040 */  lw        $s4, 0x40($sp)
/* BA7490 80242D10 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA7494 80242D14 8FB20038 */  lw        $s2, 0x38($sp)
/* BA7498 80242D18 8FB10034 */  lw        $s1, 0x34($sp)
/* BA749C 80242D1C 8FB00030 */  lw        $s0, 0x30($sp)
/* BA74A0 80242D20 03E00008 */  jr        $ra
/* BA74A4 80242D24 27BD0050 */   addiu    $sp, $sp, 0x50
/* BA74A8 80242D28 00000000 */  nop       
/* BA74AC 80242D2C 00000000 */  nop       
