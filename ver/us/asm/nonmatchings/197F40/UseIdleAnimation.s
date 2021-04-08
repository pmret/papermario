.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UseIdleAnimation
/* 19D9CC 8026F0EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19D9D0 8026F0F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 19D9D4 8026F0F4 0080902D */  daddu     $s2, $a0, $zero
/* 19D9D8 8026F0F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19D9DC 8026F0FC AFB10014 */  sw        $s1, 0x14($sp)
/* 19D9E0 8026F100 AFB00010 */  sw        $s0, 0x10($sp)
/* 19D9E4 8026F104 8E50000C */  lw        $s0, 0xc($s2)
/* 19D9E8 8026F108 8E050000 */  lw        $a1, ($s0)
/* 19D9EC 8026F10C 0C0B1EAF */  jal       get_variable
/* 19D9F0 8026F110 26100004 */   addiu    $s0, $s0, 4
/* 19D9F4 8026F114 0040882D */  daddu     $s1, $v0, $zero
/* 19D9F8 8026F118 8E050000 */  lw        $a1, ($s0)
/* 19D9FC 8026F11C 0C0B1EAF */  jal       get_variable
/* 19DA00 8026F120 0240202D */   daddu    $a0, $s2, $zero
/* 19DA04 8026F124 0040802D */  daddu     $s0, $v0, $zero
/* 19DA08 8026F128 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19DA0C 8026F12C 16220002 */  bne       $s1, $v0, .L8026F138
/* 19DA10 8026F130 00000000 */   nop
/* 19DA14 8026F134 8E510148 */  lw        $s1, 0x148($s2)
.L8026F138:
/* 19DA18 8026F138 0C09A75B */  jal       get_actor
/* 19DA1C 8026F13C 0220202D */   daddu    $a0, $s1, $zero
/* 19DA20 8026F140 1600000C */  bnez      $s0, .L8026F174
/* 19DA24 8026F144 0040202D */   daddu    $a0, $v0, $zero
/* 19DA28 8026F148 3C05FBFF */  lui       $a1, 0xfbff
/* 19DA2C 8026F14C 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 19DA30 8026F150 3C03F7FF */  lui       $v1, 0xf7ff
/* 19DA34 8026F154 8C820000 */  lw        $v0, ($a0)
/* 19DA38 8026F158 3463FFFF */  ori       $v1, $v1, 0xffff
/* 19DA3C 8026F15C 00451024 */  and       $v0, $v0, $a1
/* 19DA40 8026F160 00431024 */  and       $v0, $v0, $v1
/* 19DA44 8026F164 0C099B90 */  jal       func_80266E40
/* 19DA48 8026F168 AC820000 */   sw       $v0, ($a0)
/* 19DA4C 8026F16C 0809BC61 */  j         .L8026F184
/* 19DA50 8026F170 00000000 */   nop
.L8026F174:
/* 19DA54 8026F174 8C820000 */  lw        $v0, ($a0)
/* 19DA58 8026F178 3C030400 */  lui       $v1, 0x400
/* 19DA5C 8026F17C 00431025 */  or        $v0, $v0, $v1
/* 19DA60 8026F180 AC820000 */  sw        $v0, ($a0)
.L8026F184:
/* 19DA64 8026F184 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19DA68 8026F188 8FB20018 */  lw        $s2, 0x18($sp)
/* 19DA6C 8026F18C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19DA70 8026F190 8FB00010 */  lw        $s0, 0x10($sp)
/* 19DA74 8026F194 24020002 */  addiu     $v0, $zero, 2
/* 19DA78 8026F198 03E00008 */  jr        $ra
/* 19DA7C 8026F19C 27BD0020 */   addiu    $sp, $sp, 0x20
