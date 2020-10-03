.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120474
/* B6B74 80120474 27BDFE00 */  addiu     $sp, $sp, -0x200
/* B6B78 80120478 2402F7FF */  addiu     $v0, $zero, -0x801
/* B6B7C 8012047C 00822024 */  and       $a0, $a0, $v0
/* B6B80 80120480 3C038015 */  lui       $v1, 0x8015
/* B6B84 80120484 8C633A40 */  lw        $v1, 0x3a40($v1)
/* B6B88 80120488 00041080 */  sll       $v0, $a0, 2
/* B6B8C 8012048C AFBF01FC */  sw        $ra, 0x1fc($sp)
/* B6B90 80120490 AFB001F8 */  sw        $s0, 0x1f8($sp)
/* B6B94 80120494 00431021 */  addu      $v0, $v0, $v1
/* B6B98 80120498 8C500000 */  lw        $s0, ($v0)
/* B6B9C 8012049C 12000020 */  beqz      $s0, .L80120520
/* B6BA0 801204A0 00000000 */   nop      
/* B6BA4 801204A4 8E020000 */  lw        $v0, ($s0)
/* B6BA8 801204A8 1040001D */  beqz      $v0, .L80120520
/* B6BAC 801204AC 00000000 */   nop      
/* B6BB0 801204B0 8CA20000 */  lw        $v0, ($a1)
/* B6BB4 801204B4 84420020 */  lh        $v0, 0x20($v0)
/* B6BB8 801204B8 14400005 */  bnez      $v0, .L801204D0
/* B6BBC 801204BC 24030079 */   addiu    $v1, $zero, 0x79
/* B6BC0 801204C0 0C0480EB */  jal       func_801203AC
/* B6BC4 801204C4 00000000 */   nop      
/* B6BC8 801204C8 08048148 */  j         .L80120520
/* B6BCC 801204CC 00000000 */   nop      
.L801204D0:
/* B6BD0 801204D0 260201E4 */  addiu     $v0, $s0, 0x1e4
/* B6BD4 801204D4 3C018015 */  lui       $at, 0x8015
/* B6BD8 801204D8 AC253B68 */  sw        $a1, 0x3b68($at)
/* B6BDC 801204DC AE0502C8 */  sw        $a1, 0x2c8($s0)
/* B6BE0 801204E0 AE0002CC */  sw        $zero, 0x2cc($s0)
/* B6BE4 801204E4 AE0002D0 */  sw        $zero, 0x2d0($s0)
.L801204E8:
/* B6BE8 801204E8 AC4000E0 */  sw        $zero, 0xe0($v0)
/* B6BEC 801204EC 2463FFFF */  addiu     $v1, $v1, -1
/* B6BF0 801204F0 0461FFFD */  bgez      $v1, .L801204E8
/* B6BF4 801204F4 2442FFFC */   addiu    $v0, $v0, -4
/* B6BF8 801204F8 0200282D */  daddu     $a1, $s0, $zero
/* B6BFC 801204FC 3C028015 */  lui       $v0, 0x8015
/* B6C00 80120500 8C423B68 */  lw        $v0, 0x3b68($v0)
/* B6C04 80120504 0000302D */  daddu     $a2, $zero, $zero
/* B6C08 80120508 8C440000 */  lw        $a0, ($v0)
/* B6C0C 8012050C 0C048108 */  jal       func_80120420
/* B6C10 80120510 27A70010 */   addiu    $a3, $sp, 0x10
/* B6C14 80120514 8E020000 */  lw        $v0, ($s0)
/* B6C18 80120518 34428000 */  ori       $v0, $v0, 0x8000
/* B6C1C 8012051C AE020000 */  sw        $v0, ($s0)
.L80120520:
/* B6C20 80120520 8FBF01FC */  lw        $ra, 0x1fc($sp)
/* B6C24 80120524 8FB001F8 */  lw        $s0, 0x1f8($sp)
/* B6C28 80120528 03E00008 */  jr        $ra
/* B6C2C 8012052C 27BD0200 */   addiu    $sp, $sp, 0x200
