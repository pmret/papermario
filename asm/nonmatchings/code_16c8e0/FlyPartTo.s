.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel FlyPartTo
/* 1AA818 8027BF38 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 1AA81C 8027BF3C AFB30024 */  sw        $s3, 0x24($sp)
/* 1AA820 8027BF40 0080982D */  daddu     $s3, $a0, $zero
/* 1AA824 8027BF44 AFBF002C */  sw        $ra, 0x2c($sp)
/* 1AA828 8027BF48 AFB40028 */  sw        $s4, 0x28($sp)
/* 1AA82C 8027BF4C AFB20020 */  sw        $s2, 0x20($sp)
/* 1AA830 8027BF50 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1AA834 8027BF54 AFB00018 */  sw        $s0, 0x18($sp)
/* 1AA838 8027BF58 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 1AA83C 8027BF5C 10A0008A */  beqz      $a1, .L8027C188
/* 1AA840 8027BF60 8E71000C */   lw       $s1, 0xc($s3)
/* 1AA844 8027BF64 8E250000 */  lw        $a1, ($s1)
/* 1AA848 8027BF68 0C0B1EAF */  jal       get_variable
/* 1AA84C 8027BF6C 26310004 */   addiu    $s1, $s1, 4
/* 1AA850 8027BF70 0040802D */  daddu     $s0, $v0, $zero
/* 1AA854 8027BF74 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AA858 8027BF78 16020002 */  bne       $s0, $v0, .L8027BF84
/* 1AA85C 8027BF7C 00000000 */   nop      
/* 1AA860 8027BF80 8E700148 */  lw        $s0, 0x148($s3)
.L8027BF84:
/* 1AA864 8027BF84 8E250000 */  lw        $a1, ($s1)
/* 1AA868 8027BF88 26310004 */  addiu     $s1, $s1, 4
/* 1AA86C 8027BF8C 0C0B1EAF */  jal       get_variable
/* 1AA870 8027BF90 0260202D */   daddu    $a0, $s3, $zero
/* 1AA874 8027BF94 0200202D */  daddu     $a0, $s0, $zero
/* 1AA878 8027BF98 0C09A75B */  jal       get_actor
/* 1AA87C 8027BF9C 0040802D */   daddu    $s0, $v0, $zero
/* 1AA880 8027BFA0 0040A02D */  daddu     $s4, $v0, $zero
/* 1AA884 8027BFA4 0280202D */  daddu     $a0, $s4, $zero
/* 1AA888 8027BFA8 0C099117 */  jal       get_actor_part
/* 1AA88C 8027BFAC 0200282D */   daddu    $a1, $s0, $zero
/* 1AA890 8027BFB0 0040902D */  daddu     $s2, $v0, $zero
/* 1AA894 8027BFB4 AE740074 */  sw        $s4, 0x74($s3)
/* 1AA898 8027BFB8 AE720078 */  sw        $s2, 0x78($s3)
/* 1AA89C 8027BFBC 8E250000 */  lw        $a1, ($s1)
/* 1AA8A0 8027BFC0 26310004 */  addiu     $s1, $s1, 4
/* 1AA8A4 8027BFC4 8E500010 */  lw        $s0, 0x10($s2)
/* 1AA8A8 8027BFC8 0C0B1EAF */  jal       get_variable
/* 1AA8AC 8027BFCC 0260202D */   daddu    $a0, $s3, $zero
/* 1AA8B0 8027BFD0 44820000 */  mtc1      $v0, $f0
/* 1AA8B4 8027BFD4 00000000 */  nop       
/* 1AA8B8 8027BFD8 46800020 */  cvt.s.w   $f0, $f0
/* 1AA8BC 8027BFDC E600000C */  swc1      $f0, 0xc($s0)
/* 1AA8C0 8027BFE0 8E250000 */  lw        $a1, ($s1)
/* 1AA8C4 8027BFE4 26310004 */  addiu     $s1, $s1, 4
/* 1AA8C8 8027BFE8 0C0B1EAF */  jal       get_variable
/* 1AA8CC 8027BFEC 0260202D */   daddu    $a0, $s3, $zero
/* 1AA8D0 8027BFF0 44820000 */  mtc1      $v0, $f0
/* 1AA8D4 8027BFF4 00000000 */  nop       
/* 1AA8D8 8027BFF8 46800020 */  cvt.s.w   $f0, $f0
/* 1AA8DC 8027BFFC E6000010 */  swc1      $f0, 0x10($s0)
/* 1AA8E0 8027C000 8E250000 */  lw        $a1, ($s1)
/* 1AA8E4 8027C004 26310004 */  addiu     $s1, $s1, 4
/* 1AA8E8 8027C008 0C0B1EAF */  jal       get_variable
/* 1AA8EC 8027C00C 0260202D */   daddu    $a0, $s3, $zero
/* 1AA8F0 8027C010 44820000 */  mtc1      $v0, $f0
/* 1AA8F4 8027C014 00000000 */  nop       
/* 1AA8F8 8027C018 46800020 */  cvt.s.w   $f0, $f0
/* 1AA8FC 8027C01C E6000014 */  swc1      $f0, 0x14($s0)
/* 1AA900 8027C020 8E250000 */  lw        $a1, ($s1)
/* 1AA904 8027C024 26310004 */  addiu     $s1, $s1, 4
/* 1AA908 8027C028 0C0B1EAF */  jal       get_variable
/* 1AA90C 8027C02C 0260202D */   daddu    $a0, $s3, $zero
/* 1AA910 8027C030 A6020038 */  sh        $v0, 0x38($s0)
/* 1AA914 8027C034 8E250000 */  lw        $a1, ($s1)
/* 1AA918 8027C038 26310004 */  addiu     $s1, $s1, 4
/* 1AA91C 8027C03C 0C0B1EAF */  jal       get_variable
/* 1AA920 8027C040 0260202D */   daddu    $a0, $s3, $zero
/* 1AA924 8027C044 A602003A */  sh        $v0, 0x3a($s0)
/* 1AA928 8027C048 8E250000 */  lw        $a1, ($s1)
/* 1AA92C 8027C04C 0C0B1EAF */  jal       get_variable
/* 1AA930 8027C050 0260202D */   daddu    $a0, $s3, $zero
/* 1AA934 8027C054 AE62007C */  sw        $v0, 0x7c($s3)
/* 1AA938 8027C058 C602000C */  lwc1      $f2, 0xc($s0)
/* 1AA93C 8027C05C C640002C */  lwc1      $f0, 0x2c($s2)
/* 1AA940 8027C060 46020081 */  sub.s     $f2, $f0, $f2
/* 1AA944 8027C064 E6000000 */  swc1      $f0, ($s0)
/* 1AA948 8027C068 46021102 */  mul.s     $f4, $f2, $f2
/* 1AA94C 8027C06C 00000000 */  nop       
/* 1AA950 8027C070 E6000018 */  swc1      $f0, 0x18($s0)
/* 1AA954 8027C074 C6400030 */  lwc1      $f0, 0x30($s2)
/* 1AA958 8027C078 C6020010 */  lwc1      $f2, 0x10($s0)
/* 1AA95C 8027C07C 46020081 */  sub.s     $f2, $f0, $f2
/* 1AA960 8027C080 E6000004 */  swc1      $f0, 4($s0)
/* 1AA964 8027C084 46021182 */  mul.s     $f6, $f2, $f2
/* 1AA968 8027C088 00000000 */  nop       
/* 1AA96C 8027C08C E600001C */  swc1      $f0, 0x1c($s0)
/* 1AA970 8027C090 C6400034 */  lwc1      $f0, 0x34($s2)
/* 1AA974 8027C094 C6020014 */  lwc1      $f2, 0x14($s0)
/* 1AA978 8027C098 46020081 */  sub.s     $f2, $f0, $f2
/* 1AA97C 8027C09C 46021082 */  mul.s     $f2, $f2, $f2
/* 1AA980 8027C0A0 00000000 */  nop       
/* 1AA984 8027C0A4 46062100 */  add.s     $f4, $f4, $f6
/* 1AA988 8027C0A8 46022300 */  add.s     $f12, $f4, $f2
/* 1AA98C 8027C0AC E6000008 */  swc1      $f0, 8($s0)
/* 1AA990 8027C0B0 46006084 */  sqrt.s    $f2, $f12
/* 1AA994 8027C0B4 46021032 */  c.eq.s    $f2, $f2
/* 1AA998 8027C0B8 00000000 */  nop       
/* 1AA99C 8027C0BC 45010004 */  bc1t      .L8027C0D0
/* 1AA9A0 8027C0C0 E6000020 */   swc1     $f0, 0x20($s0)
/* 1AA9A4 8027C0C4 0C0187BC */  jal       sqrtf
/* 1AA9A8 8027C0C8 00000000 */   nop      
/* 1AA9AC 8027C0CC 46000086 */  mov.s     $f2, $f0
.L8027C0D0:
/* 1AA9B0 8027C0D0 86020038 */  lh        $v0, 0x38($s0)
/* 1AA9B4 8027C0D4 14400007 */  bnez      $v0, .L8027C0F4
/* 1AA9B8 8027C0D8 E6020034 */   swc1     $f2, 0x34($s0)
/* 1AA9BC 8027C0DC C6000028 */  lwc1      $f0, 0x28($s0)
/* 1AA9C0 8027C0E0 46001003 */  div.s     $f0, $f2, $f0
/* 1AA9C4 8027C0E4 4600020D */  trunc.w.s $f8, $f0
/* 1AA9C8 8027C0E8 44024000 */  mfc1      $v0, $f8
/* 1AA9CC 8027C0EC 0809F042 */  j         .L8027C108
/* 1AA9D0 8027C0F0 A6020038 */   sh       $v0, 0x38($s0)
.L8027C0F4:
/* 1AA9D4 8027C0F4 44820000 */  mtc1      $v0, $f0
/* 1AA9D8 8027C0F8 00000000 */  nop       
/* 1AA9DC 8027C0FC 46800020 */  cvt.s.w   $f0, $f0
/* 1AA9E0 8027C100 46001003 */  div.s     $f0, $f2, $f0
/* 1AA9E4 8027C104 E6000028 */  swc1      $f0, 0x28($s0)
.L8027C108:
/* 1AA9E8 8027C108 86020038 */  lh        $v0, 0x38($s0)
/* 1AA9EC 8027C10C 14400003 */  bnez      $v0, .L8027C11C
/* 1AA9F0 8027C110 00000000 */   nop      
.L8027C114:
/* 1AA9F4 8027C114 0809F12F */  j         .L8027C4BC
/* 1AA9F8 8027C118 24020002 */   addiu    $v0, $zero, 2
.L8027C11C:
/* 1AA9FC 8027C11C 8E4200AC */  lw        $v0, 0xac($s2)
/* 1AAA00 8027C120 5040000C */  beql      $v0, $zero, .L8027C154
/* 1AAA04 8027C124 AE00003C */   sw       $zero, 0x3c($s0)
/* 1AAA08 8027C128 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 1AAA0C 8027C12C 54400009 */  bnel      $v0, $zero, .L8027C154
/* 1AAA10 8027C130 AE00003C */   sw       $zero, 0x3c($s0)
/* 1AAA14 8027C134 C6400034 */  lwc1      $f0, 0x34($s2)
/* 1AAA18 8027C138 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AAA1C 8027C13C 8E4400AC */  lw        $a0, 0xac($s2)
/* 1AAA20 8027C140 8E46002C */  lw        $a2, 0x2c($s2)
/* 1AAA24 8027C144 8E470030 */  lw        $a3, 0x30($s2)
/* 1AAA28 8027C148 0C052757 */  jal       play_sound_at_position
/* 1AAA2C 8027C14C 0000282D */   daddu    $a1, $zero, $zero
/* 1AAA30 8027C150 AE00003C */  sw        $zero, 0x3c($s0)
.L8027C154:
/* 1AAA34 8027C154 AE000030 */  sw        $zero, 0x30($s0)
/* 1AAA38 8027C158 864200BE */  lh        $v0, 0xbe($s2)
/* 1AAA3C 8027C15C 04400004 */  bltz      $v0, .L8027C170
/* 1AAA40 8027C160 00000000 */   nop      
/* 1AAA44 8027C164 868201B6 */  lh        $v0, 0x1b6($s4)
/* 1AAA48 8027C168 0809F05E */  j         .L8027C178
/* 1AAA4C 8027C16C 24420001 */   addiu    $v0, $v0, 1
.L8027C170:
/* 1AAA50 8027C170 868201B6 */  lh        $v0, 0x1b6($s4)
/* 1AAA54 8027C174 00021027 */  nor       $v0, $zero, $v0
.L8027C178:
/* 1AAA58 8027C178 44820000 */  mtc1      $v0, $f0
/* 1AAA5C 8027C17C 00000000 */  nop       
/* 1AAA60 8027C180 46800020 */  cvt.s.w   $f0, $f0
/* 1AAA64 8027C184 E600002C */  swc1      $f0, 0x2c($s0)
.L8027C188:
/* 1AAA68 8027C188 8E720078 */  lw        $s2, 0x78($s3)
/* 1AAA6C 8027C18C 8E500010 */  lw        $s0, 0x10($s2)
/* 1AAA70 8027C190 8E740074 */  lw        $s4, 0x74($s3)
/* 1AAA74 8027C194 86020038 */  lh        $v0, 0x38($s0)
/* 1AAA78 8027C198 AFA20010 */  sw        $v0, 0x10($sp)
/* 1AAA7C 8027C19C 8E64007C */  lw        $a0, 0x7c($s3)
/* 1AAA80 8027C1A0 8E050018 */  lw        $a1, 0x18($s0)
/* 1AAA84 8027C1A4 8E06000C */  lw        $a2, 0xc($s0)
/* 1AAA88 8027C1A8 0C09EC37 */  jal       update_lerp_battle
/* 1AAA8C 8027C1AC 8E07003C */   lw       $a3, 0x3c($s0)
/* 1AAA90 8027C1B0 86020038 */  lh        $v0, 0x38($s0)
/* 1AAA94 8027C1B4 E6000000 */  swc1      $f0, ($s0)
/* 1AAA98 8027C1B8 AFA20010 */  sw        $v0, 0x10($sp)
/* 1AAA9C 8027C1BC 8E64007C */  lw        $a0, 0x7c($s3)
/* 1AAAA0 8027C1C0 8E05001C */  lw        $a1, 0x1c($s0)
/* 1AAAA4 8027C1C4 8E060010 */  lw        $a2, 0x10($s0)
/* 1AAAA8 8027C1C8 0C09EC37 */  jal       update_lerp_battle
/* 1AAAAC 8027C1CC 8E07003C */   lw       $a3, 0x3c($s0)
/* 1AAAB0 8027C1D0 86020038 */  lh        $v0, 0x38($s0)
/* 1AAAB4 8027C1D4 E6000004 */  swc1      $f0, 4($s0)
/* 1AAAB8 8027C1D8 AFA20010 */  sw        $v0, 0x10($sp)
/* 1AAABC 8027C1DC 8E64007C */  lw        $a0, 0x7c($s3)
/* 1AAAC0 8027C1E0 8E050020 */  lw        $a1, 0x20($s0)
/* 1AAAC4 8027C1E4 8E060014 */  lw        $a2, 0x14($s0)
/* 1AAAC8 8027C1E8 0C09EC37 */  jal       update_lerp_battle
/* 1AAACC 8027C1EC 8E07003C */   lw       $a3, 0x3c($s0)
/* 1AAAD0 8027C1F0 8E02003C */  lw        $v0, 0x3c($s0)
/* 1AAAD4 8027C1F4 86030038 */  lh        $v1, 0x38($s0)
/* 1AAAD8 8027C1F8 E6000008 */  swc1      $f0, 8($s0)
/* 1AAADC 8027C1FC 24420001 */  addiu     $v0, $v0, 1
/* 1AAAE0 8027C200 0062182A */  slt       $v1, $v1, $v0
/* 1AAAE4 8027C204 10600010 */  beqz      $v1, .L8027C248
/* 1AAAE8 8027C208 AE02003C */   sw       $v0, 0x3c($s0)
/* 1AAAEC 8027C20C C600000C */  lwc1      $f0, 0xc($s0)
/* 1AAAF0 8027C210 8E4400AC */  lw        $a0, 0xac($s2)
/* 1AAAF4 8027C214 E640002C */  swc1      $f0, 0x2c($s2)
/* 1AAAF8 8027C218 C6000010 */  lwc1      $f0, 0x10($s0)
/* 1AAAFC 8027C21C E6400030 */  swc1      $f0, 0x30($s2)
/* 1AAB00 8027C220 C6000014 */  lwc1      $f0, 0x14($s0)
/* 1AAB04 8027C224 1080FFBB */  beqz      $a0, .L8027C114
/* 1AAB08 8027C228 E6400034 */   swc1     $f0, 0x34($s2)
/* 1AAB0C 8027C22C 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 1AAB10 8027C230 144000A2 */  bnez      $v0, .L8027C4BC
/* 1AAB14 8027C234 24020002 */   addiu    $v0, $zero, 2
/* 1AAB18 8027C238 0C0154F0 */  jal       func_800553C0
/* 1AAB1C 8027C23C 00000000 */   nop      
/* 1AAB20 8027C240 0809F12F */  j         .L8027C4BC
/* 1AAB24 8027C244 24020002 */   addiu    $v0, $zero, 2
.L8027C248:
/* 1AAB28 8027C248 8E4200AC */  lw        $v0, 0xac($s2)
/* 1AAB2C 8027C24C 1040004A */  beqz      $v0, .L8027C378
/* 1AAB30 8027C250 00000000 */   nop      
/* 1AAB34 8027C254 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 1AAB38 8027C258 10400047 */  beqz      $v0, .L8027C378
/* 1AAB3C 8027C25C 00000000 */   nop      
/* 1AAB40 8027C260 864200BE */  lh        $v0, 0xbe($s2)
/* 1AAB44 8027C264 0440001C */  bltz      $v0, .L8027C2D8
/* 1AAB48 8027C268 00000000 */   nop      
/* 1AAB4C 8027C26C C602002C */  lwc1      $f2, 0x2c($s0)
/* 1AAB50 8027C270 C6000028 */  lwc1      $f0, 0x28($s0)
/* 1AAB54 8027C274 46001080 */  add.s     $f2, $f2, $f0
/* 1AAB58 8027C278 E602002C */  swc1      $f2, 0x2c($s0)
/* 1AAB5C 8027C27C 864200BE */  lh        $v0, 0xbe($s2)
/* 1AAB60 8027C280 44820000 */  mtc1      $v0, $f0
/* 1AAB64 8027C284 00000000 */  nop       
/* 1AAB68 8027C288 46800020 */  cvt.s.w   $f0, $f0
/* 1AAB6C 8027C28C 4602003C */  c.lt.s    $f0, $f2
/* 1AAB70 8027C290 00000000 */  nop       
/* 1AAB74 8027C294 45000038 */  bc1f      .L8027C378
/* 1AAB78 8027C298 00000000 */   nop      
/* 1AAB7C 8027C29C 92820135 */  lbu       $v0, 0x135($s4)
/* 1AAB80 8027C2A0 24420001 */  addiu     $v0, $v0, 1
/* 1AAB84 8027C2A4 A2820135 */  sb        $v0, 0x135($s4)
/* 1AAB88 8027C2A8 AE00002C */  sw        $zero, 0x2c($s0)
/* 1AAB8C 8027C2AC 92820135 */  lbu       $v0, 0x135($s4)
/* 1AAB90 8027C2B0 30420001 */  andi      $v0, $v0, 1
/* 1AAB94 8027C2B4 10400026 */  beqz      $v0, .L8027C350
/* 1AAB98 8027C2B8 00000000 */   nop      
/* 1AAB9C 8027C2BC 8E4200AC */  lw        $v0, 0xac($s2)
/* 1AABA0 8027C2C0 1040002D */  beqz      $v0, .L8027C378
/* 1AABA4 8027C2C4 00000000 */   nop      
/* 1AABA8 8027C2C8 C6400034 */  lwc1      $f0, 0x34($s2)
/* 1AABAC 8027C2CC E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AABB0 8027C2D0 0809F0DA */  j         .L8027C368
/* 1AABB4 8027C2D4 8E4400AC */   lw       $a0, 0xac($s2)
.L8027C2D8:
/* 1AABB8 8027C2D8 C602002C */  lwc1      $f2, 0x2c($s0)
/* 1AABBC 8027C2DC 3C013F80 */  lui       $at, 0x3f80
/* 1AABC0 8027C2E0 44810000 */  mtc1      $at, $f0
/* 1AABC4 8027C2E4 00000000 */  nop       
/* 1AABC8 8027C2E8 46001080 */  add.s     $f2, $f2, $f0
/* 1AABCC 8027C2EC E602002C */  swc1      $f2, 0x2c($s0)
/* 1AABD0 8027C2F0 864200BE */  lh        $v0, 0xbe($s2)
/* 1AABD4 8027C2F4 00021023 */  negu      $v0, $v0
/* 1AABD8 8027C2F8 44820000 */  mtc1      $v0, $f0
/* 1AABDC 8027C2FC 00000000 */  nop       
/* 1AABE0 8027C300 46800020 */  cvt.s.w   $f0, $f0
/* 1AABE4 8027C304 4602003E */  c.le.s    $f0, $f2
/* 1AABE8 8027C308 00000000 */  nop       
/* 1AABEC 8027C30C 4500001A */  bc1f      .L8027C378
/* 1AABF0 8027C310 00000000 */   nop      
/* 1AABF4 8027C314 92820135 */  lbu       $v0, 0x135($s4)
/* 1AABF8 8027C318 24420001 */  addiu     $v0, $v0, 1
/* 1AABFC 8027C31C A2820135 */  sb        $v0, 0x135($s4)
/* 1AAC00 8027C320 AE00002C */  sw        $zero, 0x2c($s0)
/* 1AAC04 8027C324 92820135 */  lbu       $v0, 0x135($s4)
/* 1AAC08 8027C328 30420001 */  andi      $v0, $v0, 1
/* 1AAC0C 8027C32C 10400008 */  beqz      $v0, .L8027C350
/* 1AAC10 8027C330 00000000 */   nop      
/* 1AAC14 8027C334 8E4200AC */  lw        $v0, 0xac($s2)
/* 1AAC18 8027C338 1040000F */  beqz      $v0, .L8027C378
/* 1AAC1C 8027C33C 00000000 */   nop      
/* 1AAC20 8027C340 C6400034 */  lwc1      $f0, 0x34($s2)
/* 1AAC24 8027C344 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AAC28 8027C348 0809F0DA */  j         .L8027C368
/* 1AAC2C 8027C34C 8E4400AC */   lw       $a0, 0xac($s2)
.L8027C350:
/* 1AAC30 8027C350 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 1AAC34 8027C354 10400008 */  beqz      $v0, .L8027C378
/* 1AAC38 8027C358 00000000 */   nop      
/* 1AAC3C 8027C35C C6400034 */  lwc1      $f0, 0x34($s2)
/* 1AAC40 8027C360 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AAC44 8027C364 8E4400B0 */  lw        $a0, 0xb0($s2)
.L8027C368:
/* 1AAC48 8027C368 8E46002C */  lw        $a2, 0x2c($s2)
/* 1AAC4C 8027C36C 8E470030 */  lw        $a3, 0x30($s2)
/* 1AAC50 8027C370 0C052757 */  jal       play_sound_at_position
/* 1AAC54 8027C374 0000282D */   daddu    $a1, $zero, $zero
.L8027C378:
/* 1AAC58 8027C378 C602000C */  lwc1      $f2, 0xc($s0)
/* 1AAC5C 8027C37C C6000000 */  lwc1      $f0, ($s0)
/* 1AAC60 8027C380 46001081 */  sub.s     $f2, $f2, $f0
/* 1AAC64 8027C384 46021102 */  mul.s     $f4, $f2, $f2
/* 1AAC68 8027C388 00000000 */  nop       
/* 1AAC6C 8027C38C C6000004 */  lwc1      $f0, 4($s0)
/* 1AAC70 8027C390 C6020010 */  lwc1      $f2, 0x10($s0)
/* 1AAC74 8027C394 46001081 */  sub.s     $f2, $f2, $f0
/* 1AAC78 8027C398 46021182 */  mul.s     $f6, $f2, $f2
/* 1AAC7C 8027C39C 00000000 */  nop       
/* 1AAC80 8027C3A0 C6000008 */  lwc1      $f0, 8($s0)
/* 1AAC84 8027C3A4 C6020014 */  lwc1      $f2, 0x14($s0)
/* 1AAC88 8027C3A8 46001081 */  sub.s     $f2, $f2, $f0
/* 1AAC8C 8027C3AC 46021002 */  mul.s     $f0, $f2, $f2
/* 1AAC90 8027C3B0 00000000 */  nop       
/* 1AAC94 8027C3B4 46062100 */  add.s     $f4, $f4, $f6
/* 1AAC98 8027C3B8 46002300 */  add.s     $f12, $f4, $f0
/* 1AAC9C 8027C3BC 46006004 */  sqrt.s    $f0, $f12
/* 1AACA0 8027C3C0 46000032 */  c.eq.s    $f0, $f0
/* 1AACA4 8027C3C4 00000000 */  nop       
/* 1AACA8 8027C3C8 45010003 */  bc1t      .L8027C3D8
/* 1AACAC 8027C3CC 00000000 */   nop      
/* 1AACB0 8027C3D0 0C0187BC */  jal       sqrtf
/* 1AACB4 8027C3D4 00000000 */   nop      
.L8027C3D8:
/* 1AACB8 8027C3D8 4480A000 */  mtc1      $zero, $f20
/* 1AACBC 8027C3DC 46000086 */  mov.s     $f2, $f0
/* 1AACC0 8027C3E0 46141032 */  c.eq.s    $f2, $f20
/* 1AACC4 8027C3E4 00000000 */  nop       
/* 1AACC8 8027C3E8 45000003 */  bc1f      .L8027C3F8
/* 1AACCC 8027C3EC 00000000 */   nop      
/* 1AACD0 8027C3F0 3C013F80 */  lui       $at, 0x3f80
/* 1AACD4 8027C3F4 44811000 */  mtc1      $at, $f2
.L8027C3F8:
/* 1AACD8 8027C3F8 C6000034 */  lwc1      $f0, 0x34($s0)
/* 1AACDC 8027C3FC 46140032 */  c.eq.s    $f0, $f20
/* 1AACE0 8027C400 00000000 */  nop       
/* 1AACE4 8027C404 45000006 */  bc1f      .L8027C420
/* 1AACE8 8027C408 00000000 */   nop      
/* 1AACEC 8027C40C 3C013F80 */  lui       $at, 0x3f80
/* 1AACF0 8027C410 44810000 */  mtc1      $at, $f0
/* 1AACF4 8027C414 00000000 */  nop       
/* 1AACF8 8027C418 E6000034 */  swc1      $f0, 0x34($s0)
/* 1AACFC 8027C41C C6000034 */  lwc1      $f0, 0x34($s0)
.L8027C420:
/* 1AAD00 8027C420 3C013FF0 */  lui       $at, 0x3ff0
/* 1AAD04 8027C424 44816800 */  mtc1      $at, $f13
/* 1AAD08 8027C428 44806000 */  mtc1      $zero, $f12
/* 1AAD0C 8027C42C 46001003 */  div.s     $f0, $f2, $f0
/* 1AAD10 8027C430 46000021 */  cvt.d.s   $f0, $f0
/* 1AAD14 8027C434 46206301 */  sub.d     $f12, $f12, $f0
/* 1AAD18 8027C438 3C01802A */  lui       $at, 0x802a
/* 1AAD1C 8027C43C D420DA20 */  ldc1      $f0, -0x25e0($at)
/* 1AAD20 8027C440 46206302 */  mul.d     $f12, $f12, $f0
/* 1AAD24 8027C444 00000000 */  nop       
/* 1AAD28 8027C448 0C00A8BB */  jal       sin_deg
/* 1AAD2C 8027C44C 46206320 */   cvt.s.d  $f12, $f12
/* 1AAD30 8027C450 8603003A */  lh        $v1, 0x3a($s0)
/* 1AAD34 8027C454 14600002 */  bnez      $v1, .L8027C460
/* 1AAD38 8027C458 46000106 */   mov.s    $f4, $f0
/* 1AAD3C 8027C45C 4600A106 */  mov.s     $f4, $f20
.L8027C460:
/* 1AAD40 8027C460 04610007 */  bgez      $v1, .L8027C480
/* 1AAD44 8027C464 00031023 */   negu     $v0, $v1
/* 1AAD48 8027C468 44821000 */  mtc1      $v0, $f2
/* 1AAD4C 8027C46C 00000000 */  nop       
/* 1AAD50 8027C470 468010A0 */  cvt.s.w   $f2, $f2
/* 1AAD54 8027C474 46002007 */  neg.s     $f0, $f4
/* 1AAD58 8027C478 46020102 */  mul.s     $f4, $f0, $f2
/* 1AAD5C 8027C47C 00000000 */  nop       
.L8027C480:
/* 1AAD60 8027C480 18600006 */  blez      $v1, .L8027C49C
/* 1AAD64 8027C484 00000000 */   nop      
/* 1AAD68 8027C488 44830000 */  mtc1      $v1, $f0
/* 1AAD6C 8027C48C 00000000 */  nop       
/* 1AAD70 8027C490 46800020 */  cvt.s.w   $f0, $f0
/* 1AAD74 8027C494 46002102 */  mul.s     $f4, $f4, $f0
/* 1AAD78 8027C498 00000000 */  nop       
.L8027C49C:
/* 1AAD7C 8027C49C C6000000 */  lwc1      $f0, ($s0)
/* 1AAD80 8027C4A0 E640002C */  swc1      $f0, 0x2c($s2)
/* 1AAD84 8027C4A4 C6000004 */  lwc1      $f0, 4($s0)
/* 1AAD88 8027C4A8 46040000 */  add.s     $f0, $f0, $f4
/* 1AAD8C 8027C4AC E6400030 */  swc1      $f0, 0x30($s2)
/* 1AAD90 8027C4B0 C6000008 */  lwc1      $f0, 8($s0)
/* 1AAD94 8027C4B4 0000102D */  daddu     $v0, $zero, $zero
/* 1AAD98 8027C4B8 E6400034 */  swc1      $f0, 0x34($s2)
.L8027C4BC:
/* 1AAD9C 8027C4BC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 1AADA0 8027C4C0 8FB40028 */  lw        $s4, 0x28($sp)
/* 1AADA4 8027C4C4 8FB30024 */  lw        $s3, 0x24($sp)
/* 1AADA8 8027C4C8 8FB20020 */  lw        $s2, 0x20($sp)
/* 1AADAC 8027C4CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1AADB0 8027C4D0 8FB00018 */  lw        $s0, 0x18($sp)
/* 1AADB4 8027C4D4 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 1AADB8 8027C4D8 03E00008 */  jr        $ra
/* 1AADBC 8027C4DC 27BD0038 */   addiu    $sp, $sp, 0x38
