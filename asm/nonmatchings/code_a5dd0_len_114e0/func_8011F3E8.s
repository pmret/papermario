.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011F3E8
/* B5AE8 8011F3E8 3C028007 */  lui       $v0, 0x8007
/* B5AEC 8011F3EC 8C42419C */  lw        $v0, 0x419c($v0)
/* B5AF0 8011F3F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B5AF4 8011F3F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* B5AF8 8011F3F8 80420070 */  lb        $v0, 0x70($v0)
/* B5AFC 8011F3FC 10400004 */  beqz      $v0, .L8011F410
/* B5B00 8011F400 27AA0010 */   addiu    $t2, $sp, 0x10
/* B5B04 8011F404 30820800 */  andi      $v0, $a0, 0x800
/* B5B08 8011F408 1040002F */  beqz      $v0, .L8011F4C8
/* B5B0C 8011F40C 00000000 */   nop      
.L8011F410:
/* B5B10 8011F410 2402F7FF */  addiu     $v0, $zero, -0x801
/* B5B14 8011F414 00822024 */  and       $a0, $a0, $v0
/* B5B18 8011F418 3C038015 */  lui       $v1, 0x8015
/* B5B1C 8011F41C 8C633A40 */  lw        $v1, 0x3a40($v1)
/* B5B20 8011F420 00041080 */  sll       $v0, $a0, 2
/* B5B24 8011F424 00431021 */  addu      $v0, $v0, $v1
/* B5B28 8011F428 8C490000 */  lw        $t1, ($v0)
/* B5B2C 8011F42C 11200026 */  beqz      $t1, .L8011F4C8
/* B5B30 8011F430 00000000 */   nop      
/* B5B34 8011F434 8D280000 */  lw        $t0, ($t1)
/* B5B38 8011F438 11000023 */  beqz      $t0, .L8011F4C8
/* B5B3C 8011F43C 31020040 */   andi     $v0, $t0, 0x40
/* B5B40 8011F440 14400021 */  bnez      $v0, .L8011F4C8
/* B5B44 8011F444 24020001 */   addiu    $v0, $zero, 1
/* B5B48 8011F448 3C03800A */  lui       $v1, 0x800a
/* B5B4C 8011F44C 8463A634 */  lh        $v1, -0x59cc($v1)
/* B5B50 8011F450 00621004 */  sllv      $v0, $v0, $v1
/* B5B54 8011F454 01021024 */  and       $v0, $t0, $v0
/* B5B58 8011F458 1040001B */  beqz      $v0, .L8011F4C8
/* B5B5C 8011F45C 31020080 */   andi     $v0, $t0, 0x80
/* B5B60 8011F460 14400019 */  bnez      $v0, .L8011F4C8
/* B5B64 8011F464 25220098 */   addiu    $v0, $t1, 0x98
/* B5B68 8011F468 24A30040 */  addiu     $v1, $a1, 0x40
.L8011F46C:
/* B5B6C 8011F46C 8CAB0000 */  lw        $t3, ($a1)
/* B5B70 8011F470 8CAC0004 */  lw        $t4, 4($a1)
/* B5B74 8011F474 8CAD0008 */  lw        $t5, 8($a1)
/* B5B78 8011F478 8CAE000C */  lw        $t6, 0xc($a1)
/* B5B7C 8011F47C AC4B0000 */  sw        $t3, ($v0)
/* B5B80 8011F480 AC4C0004 */  sw        $t4, 4($v0)
/* B5B84 8011F484 AC4D0008 */  sw        $t5, 8($v0)
/* B5B88 8011F488 AC4E000C */  sw        $t6, 0xc($v0)
/* B5B8C 8011F48C 24A50010 */  addiu     $a1, $a1, 0x10
/* B5B90 8011F490 14A3FFF6 */  bne       $a1, $v1, .L8011F46C
/* B5B94 8011F494 24420010 */   addiu    $v0, $v0, 0x10
/* B5B98 8011F498 3C028012 */  lui       $v0, 0x8012
/* B5B9C 8011F49C 2442F4D4 */  addiu     $v0, $v0, -0xb2c
/* B5BA0 8011F4A0 3C018015 */  lui       $at, 0x8015
/* B5BA4 8011F4A4 AC263A60 */  sw        $a2, 0x3a60($at)
/* B5BA8 8011F4A8 AD2700D8 */  sw        $a3, 0xd8($t1)
/* B5BAC 8011F4AC AD490008 */  sw        $t1, 8($t2)
/* B5BB0 8011F4B0 AD42000C */  sw        $v0, 0xc($t2)
/* B5BB4 8011F4B4 AD400004 */  sw        $zero, 4($t2)
/* B5BB8 8011F4B8 81220004 */  lb        $v0, 4($t1)
/* B5BBC 8011F4BC 0140202D */  daddu     $a0, $t2, $zero
/* B5BC0 8011F4C0 0C047644 */  jal       queue_render_task
/* B5BC4 8011F4C4 AD420000 */   sw       $v0, ($t2)
.L8011F4C8:
/* B5BC8 8011F4C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* B5BCC 8011F4CC 03E00008 */  jr        $ra
/* B5BD0 8011F4D0 27BD0028 */   addiu    $sp, $sp, 0x28
