.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _set_game_mode
/* A93A8 80112CA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A93AC 80112CAC 3C038015 */  lui       $v1, %hi(gMainGameState)
/* A93B0 80112CB0 24631700 */  addiu     $v1, $v1, %lo(gMainGameState)
/* A93B4 80112CB4 00041040 */  sll       $v0, $a0, 1
/* A93B8 80112CB8 00441021 */  addu      $v0, $v0, $a0
/* A93BC 80112CBC 000210C0 */  sll       $v0, $v0, 3
/* A93C0 80112CC0 AFB00010 */  sw        $s0, 0x10($sp)
/* A93C4 80112CC4 00438021 */  addu      $s0, $v0, $v1
/* A93C8 80112CC8 28840002 */  slti      $a0, $a0, 2
/* A93CC 80112CCC 14800003 */  bnez      $a0, .L80112CDC
/* A93D0 80112CD0 AFBF0014 */   sw       $ra, 0x14($sp)
.L80112CD4:
/* A93D4 80112CD4 08044B35 */  j         .L80112CD4
/* A93D8 80112CD8 00000000 */   nop      
.L80112CDC:
/* A93DC 80112CDC 24020003 */  addiu     $v0, $zero, 3
/* A93E0 80112CE0 A6020000 */  sh        $v0, ($s0)
/* A93E4 80112CE4 8CA20004 */  lw        $v0, 4($a1)
/* A93E8 80112CE8 AE020004 */  sw        $v0, 4($s0)
/* A93EC 80112CEC 8CA20008 */  lw        $v0, 8($a1)
/* A93F0 80112CF0 8E030004 */  lw        $v1, 4($s0)
/* A93F4 80112CF4 AE020008 */  sw        $v0, 8($s0)
/* A93F8 80112CF8 8CA20010 */  lw        $v0, 0x10($a1)
/* A93FC 80112CFC AE00000C */  sw        $zero, 0xc($s0)
/* A9400 80112D00 14600004 */  bnez      $v1, .L80112D14
/* A9404 80112D04 AE020010 */   sw       $v0, 0x10($s0)
/* A9408 80112D08 3C028011 */  lui       $v0, 0x8011
/* A940C 80112D0C 24422B90 */  addiu     $v0, $v0, 0x2b90
/* A9410 80112D10 AE020004 */  sw        $v0, 4($s0)
.L80112D14:
/* A9414 80112D14 8E020008 */  lw        $v0, 8($s0)
/* A9418 80112D18 14400004 */  bnez      $v0, .L80112D2C
/* A941C 80112D1C 00000000 */   nop      
/* A9420 80112D20 3C028011 */  lui       $v0, 0x8011
/* A9424 80112D24 24422B90 */  addiu     $v0, $v0, 0x2b90
/* A9428 80112D28 AE020008 */  sw        $v0, 8($s0)
.L80112D2C:
/* A942C 80112D2C 8E02000C */  lw        $v0, 0xc($s0)
/* A9430 80112D30 14400004 */  bnez      $v0, .L80112D44
/* A9434 80112D34 00000000 */   nop      
/* A9438 80112D38 3C028011 */  lui       $v0, 0x8011
/* A943C 80112D3C 24422B90 */  addiu     $v0, $v0, 0x2b90
/* A9440 80112D40 AE02000C */  sw        $v0, 0xc($s0)
.L80112D44:
/* A9444 80112D44 8E020010 */  lw        $v0, 0x10($s0)
/* A9448 80112D48 14400004 */  bnez      $v0, .L80112D5C
/* A944C 80112D4C 00000000 */   nop      
/* A9450 80112D50 3C028011 */  lui       $v0, 0x8011
/* A9454 80112D54 24422B90 */  addiu     $v0, $v0, 0x2b90
/* A9458 80112D58 AE020010 */  sw        $v0, 0x10($s0)
.L80112D5C:
/* A945C 80112D5C 8E030004 */  lw        $v1, 4($s0)
/* A9460 80112D60 3C028011 */  lui       $v0, 0x8011
/* A9464 80112D64 24422B90 */  addiu     $v0, $v0, 0x2b90
/* A9468 80112D68 0060F809 */  jalr      $v1
/* A946C 80112D6C AE020014 */   sw       $v0, 0x14($s0)
/* A9470 80112D70 0200102D */  daddu     $v0, $s0, $zero
/* A9474 80112D74 8FBF0014 */  lw        $ra, 0x14($sp)
/* A9478 80112D78 8FB00010 */  lw        $s0, 0x10($sp)
/* A947C 80112D7C 03E00008 */  jr        $ra
/* A9480 80112D80 27BD0018 */   addiu    $sp, $sp, 0x18
