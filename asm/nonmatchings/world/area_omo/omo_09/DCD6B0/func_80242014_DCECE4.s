.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242014_DCECE4
/* DCECE4 80242014 27BDFF98 */  addiu     $sp, $sp, -0x68
/* DCECE8 80242018 AFB30054 */  sw        $s3, 0x54($sp)
/* DCECEC 8024201C 0080982D */  daddu     $s3, $a0, $zero
/* DCECF0 80242020 AFBF0060 */  sw        $ra, 0x60($sp)
/* DCECF4 80242024 AFB5005C */  sw        $s5, 0x5c($sp)
/* DCECF8 80242028 AFB40058 */  sw        $s4, 0x58($sp)
/* DCECFC 8024202C AFB20050 */  sw        $s2, 0x50($sp)
/* DCED00 80242030 AFB1004C */  sw        $s1, 0x4c($sp)
/* DCED04 80242034 AFB00048 */  sw        $s0, 0x48($sp)
/* DCED08 80242038 8E710148 */  lw        $s1, 0x148($s3)
/* DCED0C 8024203C 86240008 */  lh        $a0, 8($s1)
/* DCED10 80242040 0C00EABB */  jal       get_npc_unsafe
/* DCED14 80242044 00A0802D */   daddu    $s0, $a1, $zero
/* DCED18 80242048 8E63000C */  lw        $v1, 0xc($s3)
/* DCED1C 8024204C 0260202D */  daddu     $a0, $s3, $zero
/* DCED20 80242050 8C650000 */  lw        $a1, ($v1)
/* DCED24 80242054 0C0B1EAF */  jal       get_variable
/* DCED28 80242058 0040902D */   daddu    $s2, $v0, $zero
/* DCED2C 8024205C AFA00018 */  sw        $zero, 0x18($sp)
/* DCED30 80242060 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DCED34 80242064 8C630094 */  lw        $v1, 0x94($v1)
/* DCED38 80242068 AFA3001C */  sw        $v1, 0x1c($sp)
/* DCED3C 8024206C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DCED40 80242070 8C630080 */  lw        $v1, 0x80($v1)
/* DCED44 80242074 AFA30020 */  sw        $v1, 0x20($sp)
/* DCED48 80242078 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DCED4C 8024207C 8C630088 */  lw        $v1, 0x88($v1)
/* DCED50 80242080 AFA30024 */  sw        $v1, 0x24($sp)
/* DCED54 80242084 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DCED58 80242088 8C63008C */  lw        $v1, 0x8c($v1)
/* DCED5C 8024208C 27B50018 */  addiu     $s5, $sp, 0x18
/* DCED60 80242090 AFA30028 */  sw        $v1, 0x28($sp)
/* DCED64 80242094 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DCED68 80242098 3C014282 */  lui       $at, 0x4282
/* DCED6C 8024209C 44810000 */  mtc1      $at, $f0
/* DCED70 802420A0 8C630090 */  lw        $v1, 0x90($v1)
/* DCED74 802420A4 0040A02D */  daddu     $s4, $v0, $zero
/* DCED78 802420A8 E7A00030 */  swc1      $f0, 0x30($sp)
/* DCED7C 802420AC A7A00034 */  sh        $zero, 0x34($sp)
/* DCED80 802420B0 16000005 */  bnez      $s0, .L802420C8
/* DCED84 802420B4 AFA3002C */   sw       $v1, 0x2c($sp)
/* DCED88 802420B8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DCED8C 802420BC 30420004 */  andi      $v0, $v0, 4
/* DCED90 802420C0 10400044 */  beqz      $v0, .L802421D4
/* DCED94 802420C4 00000000 */   nop      
.L802420C8:
/* DCED98 802420C8 2404F7FF */  addiu     $a0, $zero, -0x801
/* DCED9C 802420CC AE600070 */  sw        $zero, 0x70($s3)
/* DCEDA0 802420D0 A640008E */  sh        $zero, 0x8e($s2)
/* DCEDA4 802420D4 8E2200CC */  lw        $v0, 0xcc($s1)
/* DCEDA8 802420D8 8E430000 */  lw        $v1, ($s2)
/* DCEDAC 802420DC 8C420000 */  lw        $v0, ($v0)
/* DCEDB0 802420E0 00641824 */  and       $v1, $v1, $a0
/* DCEDB4 802420E4 AE430000 */  sw        $v1, ($s2)
/* DCEDB8 802420E8 AE420028 */  sw        $v0, 0x28($s2)
/* DCEDBC 802420EC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DCEDC0 802420F0 8C420098 */  lw        $v0, 0x98($v0)
/* DCEDC4 802420F4 54400005 */  bnel      $v0, $zero, .L8024210C
/* DCEDC8 802420F8 2402FDFF */   addiu    $v0, $zero, -0x201
/* DCEDCC 802420FC 34620200 */  ori       $v0, $v1, 0x200
/* DCEDD0 80242100 2403FFF7 */  addiu     $v1, $zero, -9
/* DCEDD4 80242104 08090845 */  j         .L80242114
/* DCEDD8 80242108 00431024 */   and      $v0, $v0, $v1
.L8024210C:
/* DCEDDC 8024210C 00621024 */  and       $v0, $v1, $v0
/* DCEDE0 80242110 34420008 */  ori       $v0, $v0, 8
.L80242114:
/* DCEDE4 80242114 AE420000 */  sw        $v0, ($s2)
/* DCEDE8 80242118 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DCEDEC 8024211C 30420004 */  andi      $v0, $v0, 4
/* DCEDF0 80242120 10400008 */  beqz      $v0, .L80242144
/* DCEDF4 80242124 24020063 */   addiu    $v0, $zero, 0x63
/* DCEDF8 80242128 AE620070 */  sw        $v0, 0x70($s3)
/* DCEDFC 8024212C AE600074 */  sw        $zero, 0x74($s3)
/* DCEE00 80242130 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DCEE04 80242134 2403FFFB */  addiu     $v1, $zero, -5
/* DCEE08 80242138 00431024 */  and       $v0, $v0, $v1
/* DCEE0C 8024213C 0809085C */  j         .L80242170
/* DCEE10 80242140 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80242144:
/* DCEE14 80242144 8E220000 */  lw        $v0, ($s1)
/* DCEE18 80242148 3C034000 */  lui       $v1, 0x4000
/* DCEE1C 8024214C 00431024 */  and       $v0, $v0, $v1
/* DCEE20 80242150 10400007 */  beqz      $v0, .L80242170
/* DCEE24 80242154 3C03BFFF */   lui      $v1, 0xbfff
/* DCEE28 80242158 2402000C */  addiu     $v0, $zero, 0xc
/* DCEE2C 8024215C AE620070 */  sw        $v0, 0x70($s3)
/* DCEE30 80242160 8E220000 */  lw        $v0, ($s1)
/* DCEE34 80242164 3463FFFF */  ori       $v1, $v1, 0xffff
/* DCEE38 80242168 00431024 */  and       $v0, $v0, $v1
/* DCEE3C 8024216C AE220000 */  sw        $v0, ($s1)
.L80242170:
/* DCEE40 80242170 27A50038 */  addiu     $a1, $sp, 0x38
/* DCEE44 80242174 27A6003C */  addiu     $a2, $sp, 0x3c
/* DCEE48 80242178 C6400038 */  lwc1      $f0, 0x38($s2)
/* DCEE4C 8024217C 864200A8 */  lh        $v0, 0xa8($s2)
/* DCEE50 80242180 3C0142C8 */  lui       $at, 0x42c8
/* DCEE54 80242184 44812000 */  mtc1      $at, $f4
/* DCEE58 80242188 44823000 */  mtc1      $v0, $f6
/* DCEE5C 8024218C 00000000 */  nop       
/* DCEE60 80242190 468031A0 */  cvt.s.w   $f6, $f6
/* DCEE64 80242194 27A20044 */  addiu     $v0, $sp, 0x44
/* DCEE68 80242198 E7A00038 */  swc1      $f0, 0x38($sp)
/* DCEE6C 8024219C C640003C */  lwc1      $f0, 0x3c($s2)
/* DCEE70 802421A0 C6420040 */  lwc1      $f2, 0x40($s2)
/* DCEE74 802421A4 46060000 */  add.s     $f0, $f0, $f6
/* DCEE78 802421A8 E7A40044 */  swc1      $f4, 0x44($sp)
/* DCEE7C 802421AC E7A20040 */  swc1      $f2, 0x40($sp)
/* DCEE80 802421B0 E7A0003C */  swc1      $f0, 0x3c($sp)
/* DCEE84 802421B4 AFA20010 */  sw        $v0, 0x10($sp)
/* DCEE88 802421B8 8E440080 */  lw        $a0, 0x80($s2)
/* DCEE8C 802421BC 0C0372DF */  jal       func_800DCB7C
/* DCEE90 802421C0 27A70040 */   addiu    $a3, $sp, 0x40
/* DCEE94 802421C4 10400003 */  beqz      $v0, .L802421D4
/* DCEE98 802421C8 00000000 */   nop      
/* DCEE9C 802421CC C7A0003C */  lwc1      $f0, 0x3c($sp)
/* DCEEA0 802421D0 E640003C */  swc1      $f0, 0x3c($s2)
.L802421D4:
/* DCEEA4 802421D4 8E630070 */  lw        $v1, 0x70($s3)
/* DCEEA8 802421D8 2C620064 */  sltiu     $v0, $v1, 0x64
/* DCEEAC 802421DC 10400054 */  beqz      $v0, .L80242330
/* DCEEB0 802421E0 00031080 */   sll      $v0, $v1, 2
/* DCEEB4 802421E4 3C018025 */  lui       $at, 0x8025
/* DCEEB8 802421E8 00220821 */  addu      $at, $at, $v0
/* DCEEBC 802421EC 8C22A980 */  lw        $v0, -0x5680($at)
/* DCEEC0 802421F0 00400008 */  jr        $v0
/* DCEEC4 802421F4 00000000 */   nop      
/* DCEEC8 802421F8 0260202D */  daddu     $a0, $s3, $zero
/* DCEECC 802421FC 0280282D */  daddu     $a1, $s4, $zero
/* DCEED0 80242200 0C0903D3 */  jal       func_80240F4C_DCDC1C
/* DCEED4 80242204 02A0302D */   daddu    $a2, $s5, $zero
/* DCEED8 80242208 0260202D */  daddu     $a0, $s3, $zero
/* DCEEDC 8024220C 0280282D */  daddu     $a1, $s4, $zero
/* DCEEE0 80242210 0C090429 */  jal       func_802410A4_DCDD74
/* DCEEE4 80242214 02A0302D */   daddu    $a2, $s5, $zero
/* DCEEE8 80242218 080908CC */  j         .L80242330
/* DCEEEC 8024221C 00000000 */   nop      
/* DCEEF0 80242220 0260202D */  daddu     $a0, $s3, $zero
/* DCEEF4 80242224 0280282D */  daddu     $a1, $s4, $zero
/* DCEEF8 80242228 0C0904D3 */  jal       UnkNpcAIFunc1
/* DCEEFC 8024222C 02A0302D */   daddu    $a2, $s5, $zero
/* DCEF00 80242230 0260202D */  daddu     $a0, $s3, $zero
/* DCEF04 80242234 0280282D */  daddu     $a1, $s4, $zero
/* DCEF08 80242238 0C090503 */  jal       func_8024140C_DCE0DC
/* DCEF0C 8024223C 02A0302D */   daddu    $a2, $s5, $zero
/* DCEF10 80242240 080908CC */  j         .L80242330
/* DCEF14 80242244 00000000 */   nop      
/* DCEF18 80242248 0260202D */  daddu     $a0, $s3, $zero
/* DCEF1C 8024224C 0280282D */  daddu     $a1, $s4, $zero
/* DCEF20 80242250 0C090572 */  jal       func_802415C8_DCE298
/* DCEF24 80242254 02A0302D */   daddu    $a2, $s5, $zero
/* DCEF28 80242258 080908CC */  j         .L80242330
/* DCEF2C 8024225C 00000000 */   nop      
/* DCEF30 80242260 0260202D */  daddu     $a0, $s3, $zero
/* DCEF34 80242264 0280282D */  daddu     $a1, $s4, $zero
/* DCEF38 80242268 0C09059F */  jal       func_8024167C_DCE34C
/* DCEF3C 8024226C 02A0302D */   daddu    $a2, $s5, $zero
/* DCEF40 80242270 0260202D */  daddu     $a0, $s3, $zero
/* DCEF44 80242274 0280282D */  daddu     $a1, $s4, $zero
/* DCEF48 80242278 0C0905BC */  jal       func_802416F0_DCE3C0
/* DCEF4C 8024227C 02A0302D */   daddu    $a2, $s5, $zero
/* DCEF50 80242280 080908CC */  j         .L80242330
/* DCEF54 80242284 00000000 */   nop      
/* DCEF58 80242288 0260202D */  daddu     $a0, $s3, $zero
/* DCEF5C 8024228C 0280282D */  daddu     $a1, $s4, $zero
/* DCEF60 80242290 0C0905DA */  jal       func_80241768_DCE438
/* DCEF64 80242294 02A0302D */   daddu    $a2, $s5, $zero
/* DCEF68 80242298 0260202D */  daddu     $a0, $s3, $zero
/* DCEF6C 8024229C 0280282D */  daddu     $a1, $s4, $zero
/* DCEF70 802422A0 0C090626 */  jal       func_80241898_DCE568
/* DCEF74 802422A4 02A0302D */   daddu    $a2, $s5, $zero
/* DCEF78 802422A8 080908CC */  j         .L80242330
/* DCEF7C 802422AC 00000000 */   nop      
/* DCEF80 802422B0 0260202D */  daddu     $a0, $s3, $zero
/* DCEF84 802422B4 0280282D */  daddu     $a1, $s4, $zero
/* DCEF88 802422B8 0C090777 */  jal       func_80241DDC_DCEAAC
/* DCEF8C 802422BC 02A0302D */   daddu    $a2, $s5, $zero
/* DCEF90 802422C0 8E630070 */  lw        $v1, 0x70($s3)
/* DCEF94 802422C4 2402000F */  addiu     $v0, $zero, 0xf
/* DCEF98 802422C8 14620019 */  bne       $v1, $v0, .L80242330
/* DCEF9C 802422CC 00000000 */   nop      
/* DCEFA0 802422D0 0260202D */  daddu     $a0, $s3, $zero
/* DCEFA4 802422D4 0280282D */  daddu     $a1, $s4, $zero
/* DCEFA8 802422D8 0C090793 */  jal       func_80241E4C_DCEB1C
/* DCEFAC 802422DC 02A0302D */   daddu    $a2, $s5, $zero
/* DCEFB0 802422E0 8E630070 */  lw        $v1, 0x70($s3)
/* DCEFB4 802422E4 24020010 */  addiu     $v0, $zero, 0x10
/* DCEFB8 802422E8 14620011 */  bne       $v1, $v0, .L80242330
/* DCEFBC 802422EC 00000000 */   nop      
/* DCEFC0 802422F0 0260202D */  daddu     $a0, $s3, $zero
/* DCEFC4 802422F4 0280282D */  daddu     $a1, $s4, $zero
/* DCEFC8 802422F8 0C0907C7 */  jal       func_80241F1C_DCEBEC
/* DCEFCC 802422FC 02A0302D */   daddu    $a2, $s5, $zero
/* DCEFD0 80242300 8E630070 */  lw        $v1, 0x70($s3)
/* DCEFD4 80242304 24020011 */  addiu     $v0, $zero, 0x11
/* DCEFD8 80242308 14620009 */  bne       $v1, $v0, .L80242330
/* DCEFDC 8024230C 00000000 */   nop      
/* DCEFE0 80242310 0260202D */  daddu     $a0, $s3, $zero
/* DCEFE4 80242314 0280282D */  daddu     $a1, $s4, $zero
/* DCEFE8 80242318 0C0907ED */  jal       func_80241FB4_DCEC84
/* DCEFEC 8024231C 02A0302D */   daddu    $a2, $s5, $zero
/* DCEFF0 80242320 080908CC */  j         .L80242330
/* DCEFF4 80242324 00000000 */   nop      
/* DCEFF8 80242328 0C0129CF */  jal       func_8004A73C
/* DCEFFC 8024232C 0260202D */   daddu    $a0, $s3, $zero
.L80242330:
/* DCF000 80242330 8FBF0060 */  lw        $ra, 0x60($sp)
/* DCF004 80242334 8FB5005C */  lw        $s5, 0x5c($sp)
/* DCF008 80242338 8FB40058 */  lw        $s4, 0x58($sp)
/* DCF00C 8024233C 8FB30054 */  lw        $s3, 0x54($sp)
/* DCF010 80242340 8FB20050 */  lw        $s2, 0x50($sp)
/* DCF014 80242344 8FB1004C */  lw        $s1, 0x4c($sp)
/* DCF018 80242348 8FB00048 */  lw        $s0, 0x48($sp)
/* DCF01C 8024234C 0000102D */  daddu     $v0, $zero, $zero
/* DCF020 80242350 03E00008 */  jr        $ra
/* DCF024 80242354 27BD0068 */   addiu    $sp, $sp, 0x68
