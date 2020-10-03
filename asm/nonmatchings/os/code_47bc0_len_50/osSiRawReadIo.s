.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSiRawReadIo
/* 47BC0 8006C7C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 47BC4 8006C7C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 47BC8 8006C7C8 00808021 */  addu      $s0, $a0, $zero
/* 47BCC 8006C7CC AFB10014 */  sw        $s1, 0x14($sp)
/* 47BD0 8006C7D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 47BD4 8006C7D4 0C01B5F8 */  jal       osSiDeviceBusy
/* 47BD8 8006C7D8 00A08821 */   addu     $s1, $a1, $zero
/* 47BDC 8006C7DC 14400006 */  bnez      $v0, .L8006C7F8
/* 47BE0 8006C7E0 2402FFFF */   addiu    $v0, $zero, -1
/* 47BE4 8006C7E4 3C02A000 */  lui       $v0, 0xa000
/* 47BE8 8006C7E8 02021025 */  or        $v0, $s0, $v0
/* 47BEC 8006C7EC 8C430000 */  lw        $v1, ($v0)
/* 47BF0 8006C7F0 00001021 */  addu      $v0, $zero, $zero
/* 47BF4 8006C7F4 AE230000 */  sw        $v1, ($s1)
.L8006C7F8:
/* 47BF8 8006C7F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 47BFC 8006C7FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 47C00 8006C800 8FB00010 */  lw        $s0, 0x10($sp)
/* 47C04 8006C804 03E00008 */  jr        $ra
/* 47C08 8006C808 27BD0020 */   addiu    $sp, $sp, 0x20
/* 47C0C 8006C80C 00000000 */  nop       
