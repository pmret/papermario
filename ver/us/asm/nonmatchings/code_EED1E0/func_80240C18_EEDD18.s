.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C18_EEDD18
/* EEDD18 80240C18 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EEDD1C 80240C1C AFB10014 */  sw        $s1, 0x14($sp)
/* EEDD20 80240C20 0080882D */  daddu     $s1, $a0, $zero
/* EEDD24 80240C24 AFB20018 */  sw        $s2, 0x18($sp)
/* EEDD28 80240C28 AFBF001C */  sw        $ra, 0x1c($sp)
/* EEDD2C 80240C2C AFB00010 */  sw        $s0, 0x10($sp)
/* EEDD30 80240C30 8E30000C */  lw        $s0, 0xc($s1)
/* EEDD34 80240C34 10A00010 */  beqz      $a1, .L80240C78
/* EEDD38 80240C38 0000902D */   daddu    $s2, $zero, $zero
/* EEDD3C 80240C3C 8E050000 */  lw        $a1, ($s0)
/* EEDD40 80240C40 0C0B53A3 */  jal       dead_get_variable
/* EEDD44 80240C44 26100004 */   addiu    $s0, $s0, 4
/* EEDD48 80240C48 AE220084 */  sw        $v0, 0x84($s1)
/* EEDD4C 80240C4C 8E050000 */  lw        $a1, ($s0)
/* EEDD50 80240C50 0C0B53A3 */  jal       dead_get_variable
/* EEDD54 80240C54 0220202D */   daddu    $a0, $s1, $zero
/* EEDD58 80240C58 0240202D */  daddu     $a0, $s2, $zero
/* EEDD5C 80240C5C 240500D0 */  addiu     $a1, $zero, 0xd0
/* EEDD60 80240C60 00A0302D */  daddu     $a2, $a1, $zero
/* EEDD64 80240C64 00A0382D */  daddu     $a3, $a1, $zero
/* EEDD68 80240C68 AE220088 */  sw        $v0, 0x88($s1)
/* EEDD6C 80240C6C AE200070 */  sw        $zero, 0x70($s1)
/* EEDD70 80240C70 0C051080 */  jal       func_80144200
/* EEDD74 80240C74 AE200074 */   sw       $zero, 0x74($s1)
.L80240C78:
/* EEDD78 80240C78 8E230070 */  lw        $v1, 0x70($s1)
/* EEDD7C 80240C7C 24040001 */  addiu     $a0, $zero, 1
/* EEDD80 80240C80 10640019 */  beq       $v1, $a0, .L80240CE8
/* EEDD84 80240C84 28620002 */   slti     $v0, $v1, 2
/* EEDD88 80240C88 10400005 */  beqz      $v0, .L80240CA0
/* EEDD8C 80240C8C 24020002 */   addiu    $v0, $zero, 2
/* EEDD90 80240C90 10600007 */  beqz      $v1, .L80240CB0
/* EEDD94 80240C94 240500FF */   addiu    $a1, $zero, 0xff
/* EEDD98 80240C98 0809034A */  j         .L80240D28
/* EEDD9C 80240C9C 00000000 */   nop
.L80240CA0:
/* EEDDA0 80240CA0 10620019 */  beq       $v1, $v0, .L80240D08
/* EEDDA4 80240CA4 00000000 */   nop
/* EEDDA8 80240CA8 0809034A */  j         .L80240D28
/* EEDDAC 80240CAC 00000000 */   nop
.L80240CB0:
/* EEDDB0 80240CB0 8E220074 */  lw        $v0, 0x74($s1)
/* EEDDB4 80240CB4 14450004 */  bne       $v0, $a1, .L80240CC8
/* EEDDB8 80240CB8 00000000 */   nop
/* EEDDBC 80240CBC AE240070 */  sw        $a0, 0x70($s1)
/* EEDDC0 80240CC0 AE200078 */  sw        $zero, 0x78($s1)
/* EEDDC4 80240CC4 8E220074 */  lw        $v0, 0x74($s1)
.L80240CC8:
/* EEDDC8 80240CC8 8E230084 */  lw        $v1, 0x84($s1)
/* EEDDCC 80240CCC 00431021 */  addu      $v0, $v0, $v1
/* EEDDD0 80240CD0 AE220074 */  sw        $v0, 0x74($s1)
/* EEDDD4 80240CD4 28420100 */  slti      $v0, $v0, 0x100
/* EEDDD8 80240CD8 50400013 */  beql      $v0, $zero, .L80240D28
/* EEDDDC 80240CDC AE250074 */   sw       $a1, 0x74($s1)
/* EEDDE0 80240CE0 0809034A */  j         .L80240D28
/* EEDDE4 80240CE4 00000000 */   nop
.L80240CE8:
/* EEDDE8 80240CE8 8E220078 */  lw        $v0, 0x78($s1)
/* EEDDEC 80240CEC 24420001 */  addiu     $v0, $v0, 1
/* EEDDF0 80240CF0 AE220078 */  sw        $v0, 0x78($s1)
/* EEDDF4 80240CF4 28420002 */  slti      $v0, $v0, 2
/* EEDDF8 80240CF8 1440000B */  bnez      $v0, .L80240D28
/* EEDDFC 80240CFC 24020002 */   addiu    $v0, $zero, 2
/* EEDE00 80240D00 0809034A */  j         .L80240D28
/* EEDE04 80240D04 AE220070 */   sw       $v0, 0x70($s1)
.L80240D08:
/* EEDE08 80240D08 8E230074 */  lw        $v1, 0x74($s1)
/* EEDE0C 80240D0C 50600001 */  beql      $v1, $zero, .L80240D14
/* EEDE10 80240D10 24120001 */   addiu    $s2, $zero, 1
.L80240D14:
/* EEDE14 80240D14 8E220088 */  lw        $v0, 0x88($s1)
/* EEDE18 80240D18 00621023 */  subu      $v0, $v1, $v0
/* EEDE1C 80240D1C 04410002 */  bgez      $v0, .L80240D28
/* EEDE20 80240D20 AE220074 */   sw       $v0, 0x74($s1)
/* EEDE24 80240D24 AE200074 */  sw        $zero, 0x74($s1)
.L80240D28:
/* EEDE28 80240D28 C6200074 */  lwc1      $f0, 0x74($s1)
/* EEDE2C 80240D2C 46800020 */  cvt.s.w   $f0, $f0
/* EEDE30 80240D30 44050000 */  mfc1      $a1, $f0
/* EEDE34 80240D34 0C05105E */  jal       func_80144178
/* EEDE38 80240D38 24040001 */   addiu    $a0, $zero, 1
/* EEDE3C 80240D3C 0240102D */  daddu     $v0, $s2, $zero
/* EEDE40 80240D40 8FBF001C */  lw        $ra, 0x1c($sp)
/* EEDE44 80240D44 8FB20018 */  lw        $s2, 0x18($sp)
/* EEDE48 80240D48 8FB10014 */  lw        $s1, 0x14($sp)
/* EEDE4C 80240D4C 8FB00010 */  lw        $s0, 0x10($sp)
/* EEDE50 80240D50 03E00008 */  jr        $ra
/* EEDE54 80240D54 27BD0020 */   addiu    $sp, $sp, 0x20
