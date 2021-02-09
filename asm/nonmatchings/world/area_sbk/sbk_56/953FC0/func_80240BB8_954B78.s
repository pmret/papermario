.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB8_954B78
/* 954B78 80240BB8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 954B7C 80240BBC AFB10014 */  sw        $s1, 0x14($sp)
/* 954B80 80240BC0 0080882D */  daddu     $s1, $a0, $zero
/* 954B84 80240BC4 AFB20018 */  sw        $s2, 0x18($sp)
/* 954B88 80240BC8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 954B8C 80240BCC AFB00010 */  sw        $s0, 0x10($sp)
/* 954B90 80240BD0 8E30000C */  lw        $s0, 0xc($s1)
/* 954B94 80240BD4 10A00010 */  beqz      $a1, .L80240C18
/* 954B98 80240BD8 0000902D */   daddu    $s2, $zero, $zero
/* 954B9C 80240BDC 8E050000 */  lw        $a1, ($s0)
/* 954BA0 80240BE0 0C0B1EAF */  jal       get_variable
/* 954BA4 80240BE4 26100004 */   addiu    $s0, $s0, 4
/* 954BA8 80240BE8 AE220084 */  sw        $v0, 0x84($s1)
/* 954BAC 80240BEC 8E050000 */  lw        $a1, ($s0)
/* 954BB0 80240BF0 0C0B1EAF */  jal       get_variable
/* 954BB4 80240BF4 0220202D */   daddu    $a0, $s1, $zero
/* 954BB8 80240BF8 0240202D */  daddu     $a0, $s2, $zero
/* 954BBC 80240BFC 240500D0 */  addiu     $a1, $zero, 0xd0
/* 954BC0 80240C00 00A0302D */  daddu     $a2, $a1, $zero
/* 954BC4 80240C04 00A0382D */  daddu     $a3, $a1, $zero
/* 954BC8 80240C08 AE220088 */  sw        $v0, 0x88($s1)
/* 954BCC 80240C0C AE200070 */  sw        $zero, 0x70($s1)
/* 954BD0 80240C10 0C04DF84 */  jal       set_transition_stencil_color
/* 954BD4 80240C14 AE200074 */   sw       $zero, 0x74($s1)
.L80240C18:
/* 954BD8 80240C18 8E230070 */  lw        $v1, 0x70($s1)
/* 954BDC 80240C1C 24040001 */  addiu     $a0, $zero, 1
/* 954BE0 80240C20 10640019 */  beq       $v1, $a0, .L80240C88
/* 954BE4 80240C24 28620002 */   slti     $v0, $v1, 2
/* 954BE8 80240C28 10400005 */  beqz      $v0, .L80240C40
/* 954BEC 80240C2C 24020002 */   addiu    $v0, $zero, 2
/* 954BF0 80240C30 10600007 */  beqz      $v1, .L80240C50
/* 954BF4 80240C34 240500FF */   addiu    $a1, $zero, 0xff
/* 954BF8 80240C38 08090332 */  j         .L80240CC8
/* 954BFC 80240C3C 00000000 */   nop
.L80240C40:
/* 954C00 80240C40 10620019 */  beq       $v1, $v0, .L80240CA8
/* 954C04 80240C44 00000000 */   nop
/* 954C08 80240C48 08090332 */  j         .L80240CC8
/* 954C0C 80240C4C 00000000 */   nop
.L80240C50:
/* 954C10 80240C50 8E220074 */  lw        $v0, 0x74($s1)
/* 954C14 80240C54 14450004 */  bne       $v0, $a1, .L80240C68
/* 954C18 80240C58 00000000 */   nop
/* 954C1C 80240C5C AE240070 */  sw        $a0, 0x70($s1)
/* 954C20 80240C60 AE200078 */  sw        $zero, 0x78($s1)
/* 954C24 80240C64 8E220074 */  lw        $v0, 0x74($s1)
.L80240C68:
/* 954C28 80240C68 8E230084 */  lw        $v1, 0x84($s1)
/* 954C2C 80240C6C 00431021 */  addu      $v0, $v0, $v1
/* 954C30 80240C70 AE220074 */  sw        $v0, 0x74($s1)
/* 954C34 80240C74 28420100 */  slti      $v0, $v0, 0x100
/* 954C38 80240C78 50400013 */  beql      $v0, $zero, .L80240CC8
/* 954C3C 80240C7C AE250074 */   sw       $a1, 0x74($s1)
/* 954C40 80240C80 08090332 */  j         .L80240CC8
/* 954C44 80240C84 00000000 */   nop
.L80240C88:
/* 954C48 80240C88 8E220078 */  lw        $v0, 0x78($s1)
/* 954C4C 80240C8C 24420001 */  addiu     $v0, $v0, 1
/* 954C50 80240C90 AE220078 */  sw        $v0, 0x78($s1)
/* 954C54 80240C94 28420002 */  slti      $v0, $v0, 2
/* 954C58 80240C98 1440000B */  bnez      $v0, .L80240CC8
/* 954C5C 80240C9C 24020002 */   addiu    $v0, $zero, 2
/* 954C60 80240CA0 08090332 */  j         .L80240CC8
/* 954C64 80240CA4 AE220070 */   sw       $v0, 0x70($s1)
.L80240CA8:
/* 954C68 80240CA8 8E230074 */  lw        $v1, 0x74($s1)
/* 954C6C 80240CAC 50600001 */  beql      $v1, $zero, .L80240CB4
/* 954C70 80240CB0 24120001 */   addiu    $s2, $zero, 1
.L80240CB4:
/* 954C74 80240CB4 8E220088 */  lw        $v0, 0x88($s1)
/* 954C78 80240CB8 00621023 */  subu      $v0, $v1, $v0
/* 954C7C 80240CBC 04410002 */  bgez      $v0, .L80240CC8
/* 954C80 80240CC0 AE220074 */   sw       $v0, 0x74($s1)
/* 954C84 80240CC4 AE200074 */  sw        $zero, 0x74($s1)
.L80240CC8:
/* 954C88 80240CC8 C6200074 */  lwc1      $f0, 0x74($s1)
/* 954C8C 80240CCC 46800020 */  cvt.s.w   $f0, $f0
/* 954C90 80240CD0 44050000 */  mfc1      $a1, $f0
/* 954C94 80240CD4 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 954C98 80240CD8 24040001 */   addiu    $a0, $zero, 1
/* 954C9C 80240CDC 0240102D */  daddu     $v0, $s2, $zero
/* 954CA0 80240CE0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 954CA4 80240CE4 8FB20018 */  lw        $s2, 0x18($sp)
/* 954CA8 80240CE8 8FB10014 */  lw        $s1, 0x14($sp)
/* 954CAC 80240CEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 954CB0 80240CF0 03E00008 */  jr        $ra
/* 954CB4 80240CF4 27BD0020 */   addiu    $sp, $sp, 0x20
