.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238000_6FAD10
/* 6FAD10 80238000 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 6FAD14 80238004 AFB10014 */  sw        $s1, 0x14($sp)
/* 6FAD18 80238008 0080882D */  daddu     $s1, $a0, $zero
/* 6FAD1C 8023800C AFBF0020 */  sw        $ra, 0x20($sp)
/* 6FAD20 80238010 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6FAD24 80238014 AFB20018 */  sw        $s2, 0x18($sp)
/* 6FAD28 80238018 AFB00010 */  sw        $s0, 0x10($sp)
/* 6FAD2C 8023801C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 6FAD30 80238020 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 6FAD34 80238024 8E30000C */  lw        $s0, 0xc($s1)
/* 6FAD38 80238028 8E050000 */  lw        $a1, ($s0)
/* 6FAD3C 8023802C 0C0B1EAF */  jal       get_variable
/* 6FAD40 80238030 26100004 */   addiu    $s0, $s0, 4
/* 6FAD44 80238034 8E050000 */  lw        $a1, ($s0)
/* 6FAD48 80238038 26100004 */  addiu     $s0, $s0, 4
/* 6FAD4C 8023803C 0220202D */  daddu     $a0, $s1, $zero
/* 6FAD50 80238040 0C0B1EAF */  jal       get_variable
/* 6FAD54 80238044 0040982D */   daddu    $s3, $v0, $zero
/* 6FAD58 80238048 0220202D */  daddu     $a0, $s1, $zero
/* 6FAD5C 8023804C 8E050000 */  lw        $a1, ($s0)
/* 6FAD60 80238050 0C0B1EAF */  jal       get_variable
/* 6FAD64 80238054 0040802D */   daddu    $s0, $v0, $zero
/* 6FAD68 80238058 4493A000 */  mtc1      $s3, $f20
/* 6FAD6C 8023805C 00000000 */  nop       
/* 6FAD70 80238060 4680A520 */  cvt.s.w   $f20, $f20
/* 6FAD74 80238064 0040902D */  daddu     $s2, $v0, $zero
/* 6FAD78 80238068 4492B000 */  mtc1      $s2, $f22
/* 6FAD7C 8023806C 00000000 */  nop       
/* 6FAD80 80238070 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6FAD84 80238074 44900000 */  mtc1      $s0, $f0
/* 6FAD88 80238078 00000000 */  nop       
/* 6FAD8C 8023807C 46800020 */  cvt.s.w   $f0, $f0
/* 6FAD90 80238080 4405A000 */  mfc1      $a1, $f20
/* 6FAD94 80238084 4407B000 */  mfc1      $a3, $f22
/* 6FAD98 80238088 44060000 */  mfc1      $a2, $f0
/* 6FAD9C 8023808C 0C01C04C */  jal       func_80070130
/* 6FADA0 80238090 0000202D */   daddu    $a0, $zero, $zero
/* 6FADA4 80238094 3C03800E */  lui       $v1, %hi(gBattleStatus+0x17C)
/* 6FADA8 80238098 8463C1EC */  lh        $v1, %lo(gBattleStatus+0x17C)($v1)
/* 6FADAC 8023809C 24020093 */  addiu     $v0, $zero, 0x93
/* 6FADB0 802380A0 1062001F */  beq       $v1, $v0, .L80238120
/* 6FADB4 802380A4 28620094 */   slti     $v0, $v1, 0x94
/* 6FADB8 802380A8 10400005 */  beqz      $v0, .L802380C0
/* 6FADBC 802380AC 24020092 */   addiu    $v0, $zero, 0x92
/* 6FADC0 802380B0 10620008 */  beq       $v1, $v0, .L802380D4
/* 6FADC4 802380B4 00000000 */   nop      
/* 6FADC8 802380B8 0808E074 */  j         .L802381D0
/* 6FADCC 802380BC 00000000 */   nop      
.L802380C0:
/* 6FADD0 802380C0 24020094 */  addiu     $v0, $zero, 0x94
/* 6FADD4 802380C4 1062002C */  beq       $v1, $v0, .L80238178
/* 6FADD8 802380C8 00000000 */   nop      
/* 6FADDC 802380CC 0808E074 */  j         .L802381D0
/* 6FADE0 802380D0 00000000 */   nop      
.L802380D4:
/* 6FADE4 802380D4 8E2200AC */  lw        $v0, 0xac($s1)
/* 6FADE8 802380D8 18400009 */  blez      $v0, .L80238100
/* 6FADEC 802380DC 26020014 */   addiu    $v0, $s0, 0x14
/* 6FADF0 802380E0 44820000 */  mtc1      $v0, $f0
/* 6FADF4 802380E4 00000000 */  nop       
/* 6FADF8 802380E8 46800020 */  cvt.s.w   $f0, $f0
/* 6FADFC 802380EC 4405A000 */  mfc1      $a1, $f20
/* 6FAE00 802380F0 4407B000 */  mfc1      $a3, $f22
/* 6FAE04 802380F4 44060000 */  mfc1      $a2, $f0
/* 6FAE08 802380F8 0808E082 */  j         .L80238208
/* 6FAE0C 802380FC 24040001 */   addiu    $a0, $zero, 1
.L80238100:
/* 6FAE10 80238100 44820000 */  mtc1      $v0, $f0
/* 6FAE14 80238104 00000000 */  nop       
/* 6FAE18 80238108 46800020 */  cvt.s.w   $f0, $f0
/* 6FAE1C 8023810C 4405A000 */  mfc1      $a1, $f20
/* 6FAE20 80238110 4407B000 */  mfc1      $a3, $f22
/* 6FAE24 80238114 44060000 */  mfc1      $a2, $f0
/* 6FAE28 80238118 0808E082 */  j         .L80238208
/* 6FAE2C 8023811C 0000202D */   daddu    $a0, $zero, $zero
.L80238120:
/* 6FAE30 80238120 8E2200AC */  lw        $v0, 0xac($s1)
/* 6FAE34 80238124 18400009 */  blez      $v0, .L8023814C
/* 6FAE38 80238128 26020014 */   addiu    $v0, $s0, 0x14
/* 6FAE3C 8023812C 44820000 */  mtc1      $v0, $f0
/* 6FAE40 80238130 00000000 */  nop       
/* 6FAE44 80238134 46800020 */  cvt.s.w   $f0, $f0
/* 6FAE48 80238138 4405A000 */  mfc1      $a1, $f20
/* 6FAE4C 8023813C 4407B000 */  mfc1      $a3, $f22
/* 6FAE50 80238140 44060000 */  mfc1      $a2, $f0
/* 6FAE54 80238144 0808E05A */  j         .L80238168
/* 6FAE58 80238148 24040001 */   addiu    $a0, $zero, 1
.L8023814C:
/* 6FAE5C 8023814C 44820000 */  mtc1      $v0, $f0
/* 6FAE60 80238150 00000000 */  nop       
/* 6FAE64 80238154 46800020 */  cvt.s.w   $f0, $f0
/* 6FAE68 80238158 4405A000 */  mfc1      $a1, $f20
/* 6FAE6C 8023815C 4407B000 */  mfc1      $a3, $f22
/* 6FAE70 80238160 44060000 */  mfc1      $a2, $f0
/* 6FAE74 80238164 0000202D */  daddu     $a0, $zero, $zero
.L80238168:
/* 6FAE78 80238168 0C01C07C */  jal       func_800701F0
/* 6FAE7C 8023816C 00000000 */   nop      
/* 6FAE80 80238170 0808E085 */  j         .L80238214
/* 6FAE84 80238174 24042017 */   addiu    $a0, $zero, 0x2017
.L80238178:
/* 6FAE88 80238178 8E2200AC */  lw        $v0, 0xac($s1)
/* 6FAE8C 8023817C 18400009 */  blez      $v0, .L802381A4
/* 6FAE90 80238180 26020014 */   addiu    $v0, $s0, 0x14
/* 6FAE94 80238184 44820000 */  mtc1      $v0, $f0
/* 6FAE98 80238188 00000000 */  nop       
/* 6FAE9C 8023818C 46800020 */  cvt.s.w   $f0, $f0
/* 6FAEA0 80238190 4405A000 */  mfc1      $a1, $f20
/* 6FAEA4 80238194 4407B000 */  mfc1      $a3, $f22
/* 6FAEA8 80238198 44060000 */  mfc1      $a2, $f0
/* 6FAEAC 8023819C 0808E070 */  j         .L802381C0
/* 6FAEB0 802381A0 24040002 */   addiu    $a0, $zero, 2
.L802381A4:
/* 6FAEB4 802381A4 44820000 */  mtc1      $v0, $f0
/* 6FAEB8 802381A8 00000000 */  nop       
/* 6FAEBC 802381AC 46800020 */  cvt.s.w   $f0, $f0
/* 6FAEC0 802381B0 4405A000 */  mfc1      $a1, $f20
/* 6FAEC4 802381B4 4407B000 */  mfc1      $a3, $f22
/* 6FAEC8 802381B8 44060000 */  mfc1      $a2, $f0
/* 6FAECC 802381BC 24040001 */  addiu     $a0, $zero, 1
.L802381C0:
/* 6FAED0 802381C0 0C01C07C */  jal       func_800701F0
/* 6FAED4 802381C4 00000000 */   nop      
/* 6FAED8 802381C8 0808E085 */  j         .L80238214
/* 6FAEDC 802381CC 24042017 */   addiu    $a0, $zero, 0x2017
.L802381D0:
/* 6FAEE0 802381D0 44930000 */  mtc1      $s3, $f0
/* 6FAEE4 802381D4 00000000 */  nop       
/* 6FAEE8 802381D8 46800020 */  cvt.s.w   $f0, $f0
/* 6FAEEC 802381DC 26020014 */  addiu     $v0, $s0, 0x14
/* 6FAEF0 802381E0 44050000 */  mfc1      $a1, $f0
/* 6FAEF4 802381E4 44820000 */  mtc1      $v0, $f0
/* 6FAEF8 802381E8 00000000 */  nop       
/* 6FAEFC 802381EC 46800020 */  cvt.s.w   $f0, $f0
/* 6FAF00 802381F0 44060000 */  mfc1      $a2, $f0
/* 6FAF04 802381F4 44920000 */  mtc1      $s2, $f0
/* 6FAF08 802381F8 00000000 */  nop       
/* 6FAF0C 802381FC 46800020 */  cvt.s.w   $f0, $f0
/* 6FAF10 80238200 44070000 */  mfc1      $a3, $f0
/* 6FAF14 80238204 0000202D */  daddu     $a0, $zero, $zero
.L80238208:
/* 6FAF18 80238208 0C01C07C */  jal       func_800701F0
/* 6FAF1C 8023820C 00000000 */   nop      
/* 6FAF20 80238210 24042016 */  addiu     $a0, $zero, 0x2016
.L80238214:
/* 6FAF24 80238214 0C05272D */  jal       play_sound
/* 6FAF28 80238218 00000000 */   nop      
/* 6FAF2C 8023821C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6FAF30 80238220 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6FAF34 80238224 8FB20018 */  lw        $s2, 0x18($sp)
/* 6FAF38 80238228 8FB10014 */  lw        $s1, 0x14($sp)
/* 6FAF3C 8023822C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6FAF40 80238230 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 6FAF44 80238234 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 6FAF48 80238238 24020002 */  addiu     $v0, $zero, 2
/* 6FAF4C 8023823C 03E00008 */  jr        $ra
/* 6FAF50 80238240 27BD0038 */   addiu    $sp, $sp, 0x38
