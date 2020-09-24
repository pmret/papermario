.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContDataGet
/* 3AA50 8005F650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3AA54 8005F654 AFB10014 */  sw        $s1, 0x14($sp)
/* 3AA58 8005F658 0080882D */  daddu     $s1, $a0, $zero
/* 3AA5C 8005F65C AFB00010 */  sw        $s0, 0x10($sp)
/* 3AA60 8005F660 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3AA64 8005F664 0C018183 */  jal       nuContDataClose
/* 3AA68 8005F668 00A0802D */   daddu    $s0, $a1, $zero
/* 3AA6C 8005F66C 00102040 */  sll       $a0, $s0, 1
/* 3AA70 8005F670 00902021 */  addu      $a0, $a0, $s0
/* 3AA74 8005F674 00042040 */  sll       $a0, $a0, 1
/* 3AA78 8005F678 3C02800B */  lui       $v0, 0x800b
/* 3AA7C 8005F67C 24421D68 */  addiu     $v0, $v0, 0x1d68
/* 3AA80 8005F680 00822021 */  addu      $a0, $a0, $v0
/* 3AA84 8005F684 0220282D */  daddu     $a1, $s1, $zero
/* 3AA88 8005F688 0C019194 */  jal       bcopy
/* 3AA8C 8005F68C 24060006 */   addiu    $a2, $zero, 6
/* 3AA90 8005F690 0C01818D */  jal       nuContDataOpen
/* 3AA94 8005F694 00000000 */   nop      
/* 3AA98 8005F698 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3AA9C 8005F69C 8FB10014 */  lw        $s1, 0x14($sp)
/* 3AAA0 8005F6A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 3AAA4 8005F6A4 03E00008 */  jr        $ra
/* 3AAA8 8005F6A8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3AAAC 8005F6AC 00000000 */  nop       
