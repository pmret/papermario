.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425A8_833DA8
/* 833DA8 802425A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 833DAC 802425AC AFB00010 */  sw        $s0, 0x10($sp)
/* 833DB0 802425B0 0080802D */  daddu     $s0, $a0, $zero
/* 833DB4 802425B4 3C05FD05 */  lui       $a1, 0xfd05
/* 833DB8 802425B8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 833DBC 802425BC 0C0B1EAF */  jal       get_variable
/* 833DC0 802425C0 34A50F82 */   ori      $a1, $a1, 0xf82
/* 833DC4 802425C4 8E03000C */  lw        $v1, 0xc($s0)
/* 833DC8 802425C8 0200202D */  daddu     $a0, $s0, $zero
/* 833DCC 802425CC 8C650000 */  lw        $a1, ($v1)
/* 833DD0 802425D0 0C0B1EAF */  jal       get_variable
/* 833DD4 802425D4 0040802D */   daddu    $s0, $v0, $zero
/* 833DD8 802425D8 8E05000C */  lw        $a1, 0xc($s0)
/* 833DDC 802425DC 00021880 */  sll       $v1, $v0, 2
/* 833DE0 802425E0 00A32821 */  addu      $a1, $a1, $v1
/* 833DE4 802425E4 8CA30008 */  lw        $v1, 8($a1)
/* 833DE8 802425E8 2404FFFE */  addiu     $a0, $zero, -2
/* 833DEC 802425EC 00641824 */  and       $v1, $v1, $a0
/* 833DF0 802425F0 ACA30008 */  sw        $v1, 8($a1)
/* 833DF4 802425F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 833DF8 802425F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 833DFC 802425FC 24020002 */  addiu     $v0, $zero, 2
/* 833E00 80242600 03E00008 */  jr        $ra
/* 833E04 80242604 27BD0018 */   addiu    $sp, $sp, 0x18
