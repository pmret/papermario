.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DE124
/* 3D8844 E00DE124 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D8848 E00DE128 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D884C E00DE12C 8C850000 */  lw        $a1, ($a0)
/* 3D8850 E00DE130 8C83000C */  lw        $v1, 0xc($a0)
/* 3D8854 E00DE134 30A20010 */  andi      $v0, $a1, 0x10
/* 3D8858 E00DE138 8C660000 */  lw        $a2, ($v1)
/* 3D885C E00DE13C 10400005 */  beqz      $v0, .LE00DE154
/* 3D8860 E00DE140 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D8864 E00DE144 00A21024 */  and       $v0, $a1, $v0
/* 3D8868 E00DE148 AC820000 */  sw        $v0, ($a0)
/* 3D886C E00DE14C 24020010 */  addiu     $v0, $zero, 0x10
/* 3D8870 E00DE150 AC620010 */  sw        $v0, 0x10($v1)
.LE00DE154:
/* 3D8874 E00DE154 8C650010 */  lw        $a1, 0x10($v1)
/* 3D8878 E00DE158 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 3D887C E00DE15C 10400002 */  beqz      $v0, .LE00DE168
/* 3D8880 E00DE160 24A2FFFF */   addiu    $v0, $a1, -1
/* 3D8884 E00DE164 AC620010 */  sw        $v0, 0x10($v1)
.LE00DE168:
/* 3D8888 E00DE168 8C620014 */  lw        $v0, 0x14($v1)
/* 3D888C E00DE16C 8C650010 */  lw        $a1, 0x10($v1)
/* 3D8890 E00DE170 24420001 */  addiu     $v0, $v0, 1
/* 3D8894 E00DE174 04A10005 */  bgez      $a1, .LE00DE18C
/* 3D8898 E00DE178 AC620014 */   sw       $v0, 0x14($v1)
/* 3D889C E00DE17C 0C080128 */  jal       func_E02004A0
/* 3D88A0 E00DE180 00000000 */   nop
/* 3D88A4 E00DE184 08037895 */  j         .LE00DE254
/* 3D88A8 E00DE188 00000000 */   nop
.LE00DE18C:
/* 3D88AC E00DE18C 28A20010 */  slti      $v0, $a1, 0x10
/* 3D88B0 E00DE190 10400002 */  beqz      $v0, .LE00DE19C
/* 3D88B4 E00DE194 00051100 */   sll      $v0, $a1, 4
/* 3D88B8 E00DE198 AC620024 */  sw        $v0, 0x24($v1)
.LE00DE19C:
/* 3D88BC E00DE19C 28C20002 */  slti      $v0, $a2, 2
/* 3D88C0 E00DE1A0 1040000A */  beqz      $v0, .LE00DE1CC
/* 3D88C4 E00DE1A4 00000000 */   nop
/* 3D88C8 E00DE1A8 04C00008 */  bltz      $a2, .LE00DE1CC
/* 3D88CC E00DE1AC 00000000 */   nop
/* 3D88D0 E00DE1B0 C460003C */  lwc1      $f0, 0x3c($v1)
/* 3D88D4 E00DE1B4 3C01E00E */  lui       $at, %hi(D_E00DE9D0)
/* 3D88D8 E00DE1B8 D422E9D0 */  ldc1      $f2, %lo(D_E00DE9D0)($at)
/* 3D88DC E00DE1BC 46000021 */  cvt.d.s   $f0, $f0
/* 3D88E0 E00DE1C0 46220000 */  add.d     $f0, $f0, $f2
/* 3D88E4 E00DE1C4 46200020 */  cvt.s.d   $f0, $f0
/* 3D88E8 E00DE1C8 E460003C */  swc1      $f0, 0x3c($v1)
.LE00DE1CC:
/* 3D88EC E00DE1CC C4640008 */  lwc1      $f4, 8($v1)
/* 3D88F0 E00DE1D0 C460003C */  lwc1      $f0, 0x3c($v1)
/* 3D88F4 E00DE1D4 46002100 */  add.s     $f4, $f4, $f0
/* 3D88F8 E00DE1D8 3C013FE0 */  lui       $at, 0x3fe0
/* 3D88FC E00DE1DC 44811800 */  mtc1      $at, $f3
/* 3D8900 E00DE1E0 44801000 */  mtc1      $zero, $f2
/* 3D8904 E00DE1E4 46000021 */  cvt.d.s   $f0, $f0
/* 3D8908 E00DE1E8 4620103C */  c.lt.d    $f2, $f0
/* 3D890C E00DE1EC 00000000 */  nop
/* 3D8910 E00DE1F0 45000005 */  bc1f      .LE00DE208
/* 3D8914 E00DE1F4 E4640008 */   swc1     $f4, 8($v1)
/* 3D8918 E00DE1F8 3C013F00 */  lui       $at, 0x3f00
/* 3D891C E00DE1FC 44810000 */  mtc1      $at, $f0
/* 3D8920 E00DE200 00000000 */  nop
/* 3D8924 E00DE204 E460003C */  swc1      $f0, 0x3c($v1)
.LE00DE208:
/* 3D8928 E00DE208 C460003C */  lwc1      $f0, 0x3c($v1)
/* 3D892C E00DE20C 3C01BFF8 */  lui       $at, 0xbff8
/* 3D8930 E00DE210 44811800 */  mtc1      $at, $f3
/* 3D8934 E00DE214 44801000 */  mtc1      $zero, $f2
/* 3D8938 E00DE218 46000021 */  cvt.d.s   $f0, $f0
/* 3D893C E00DE21C 4622003C */  c.lt.d    $f0, $f2
/* 3D8940 E00DE220 00000000 */  nop
/* 3D8944 E00DE224 45000005 */  bc1f      .LE00DE23C
/* 3D8948 E00DE228 00000000 */   nop
/* 3D894C E00DE22C 3C01BFC0 */  lui       $at, 0xbfc0
/* 3D8950 E00DE230 44810000 */  mtc1      $at, $f0
/* 3D8954 E00DE234 00000000 */  nop
/* 3D8958 E00DE238 E460003C */  swc1      $f0, 0x3c($v1)
.LE00DE23C:
/* 3D895C E00DE23C C4600038 */  lwc1      $f0, 0x38($v1)
/* 3D8960 E00DE240 3C013F80 */  lui       $at, 0x3f80
/* 3D8964 E00DE244 44811000 */  mtc1      $at, $f2
/* 3D8968 E00DE248 00000000 */  nop
/* 3D896C E00DE24C 46020000 */  add.s     $f0, $f0, $f2
/* 3D8970 E00DE250 E4600038 */  swc1      $f0, 0x38($v1)
.LE00DE254:
/* 3D8974 E00DE254 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D8978 E00DE258 03E00008 */  jr        $ra
/* 3D897C E00DE25C 27BD0018 */   addiu    $sp, $sp, 0x18
