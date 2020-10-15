.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetActorPos
/* 199388 8026AAA8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19938C 8026AAAC AFB40020 */  sw        $s4, 0x20($sp)
/* 199390 8026AAB0 0080A02D */  daddu     $s4, $a0, $zero
/* 199394 8026AAB4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 199398 8026AAB8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19939C 8026AABC AFB20018 */  sw        $s2, 0x18($sp)
/* 1993A0 8026AAC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1993A4 8026AAC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1993A8 8026AAC8 8E92000C */  lw        $s2, 0xc($s4)
/* 1993AC 8026AACC 8E450000 */  lw        $a1, ($s2)
/* 1993B0 8026AAD0 0C0B1EAF */  jal       get_variable
/* 1993B4 8026AAD4 26520004 */   addiu    $s2, $s2, 4
/* 1993B8 8026AAD8 0040202D */  daddu     $a0, $v0, $zero
/* 1993BC 8026AADC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1993C0 8026AAE0 14820002 */  bne       $a0, $v0, .L8026AAEC
/* 1993C4 8026AAE4 00000000 */   nop      
/* 1993C8 8026AAE8 8E840148 */  lw        $a0, 0x148($s4)
.L8026AAEC:
/* 1993CC 8026AAEC 0C09A75B */  jal       get_actor
/* 1993D0 8026AAF0 00000000 */   nop      
/* 1993D4 8026AAF4 8E450000 */  lw        $a1, ($s2)
/* 1993D8 8026AAF8 26520004 */  addiu     $s2, $s2, 4
/* 1993DC 8026AAFC C4400144 */  lwc1      $f0, 0x144($v0)
/* 1993E0 8026AB00 C442014C */  lwc1      $f2, 0x14c($v0)
/* 1993E4 8026AB04 8E500000 */  lw        $s0, ($s2)
/* 1993E8 8026AB08 4600010D */  trunc.w.s $f4, $f0
/* 1993EC 8026AB0C 44062000 */  mfc1      $a2, $f4
/* 1993F0 8026AB10 C4400148 */  lwc1      $f0, 0x148($v0)
/* 1993F4 8026AB14 8E520004 */  lw        $s2, 4($s2)
/* 1993F8 8026AB18 4600010D */  trunc.w.s $f4, $f0
/* 1993FC 8026AB1C 44112000 */  mfc1      $s1, $f4
/* 199400 8026AB20 4600110D */  trunc.w.s $f4, $f2
/* 199404 8026AB24 44132000 */  mfc1      $s3, $f4
/* 199408 8026AB28 0C0B2026 */  jal       set_variable
/* 19940C 8026AB2C 0280202D */   daddu    $a0, $s4, $zero
/* 199410 8026AB30 0280202D */  daddu     $a0, $s4, $zero
/* 199414 8026AB34 0200282D */  daddu     $a1, $s0, $zero
/* 199418 8026AB38 0C0B2026 */  jal       set_variable
/* 19941C 8026AB3C 0220302D */   daddu    $a2, $s1, $zero
/* 199420 8026AB40 0280202D */  daddu     $a0, $s4, $zero
/* 199424 8026AB44 0240282D */  daddu     $a1, $s2, $zero
/* 199428 8026AB48 0C0B2026 */  jal       set_variable
/* 19942C 8026AB4C 0260302D */   daddu    $a2, $s3, $zero
/* 199430 8026AB50 8FBF0024 */  lw        $ra, 0x24($sp)
/* 199434 8026AB54 8FB40020 */  lw        $s4, 0x20($sp)
/* 199438 8026AB58 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19943C 8026AB5C 8FB20018 */  lw        $s2, 0x18($sp)
/* 199440 8026AB60 8FB10014 */  lw        $s1, 0x14($sp)
/* 199444 8026AB64 8FB00010 */  lw        $s0, 0x10($sp)
/* 199448 8026AB68 24020002 */  addiu     $v0, $zero, 2
/* 19944C 8026AB6C 03E00008 */  jr        $ra
/* 199450 8026AB70 27BD0028 */   addiu    $sp, $sp, 0x28
