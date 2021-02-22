.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E01140DC
/* 3FEBBC E01140DC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3FEBC0 E01140E0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 3FEBC4 E01140E4 AFB50024 */  sw        $s5, 0x24($sp)
/* 3FEBC8 E01140E8 AFB40020 */  sw        $s4, 0x20($sp)
/* 3FEBCC E01140EC AFB3001C */  sw        $s3, 0x1c($sp)
/* 3FEBD0 E01140F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 3FEBD4 E01140F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 3FEBD8 E01140F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 3FEBDC E01140FC 8C94000C */  lw        $s4, 0xc($a0)
/* 3FEBE0 E0114100 3C15E011 */  lui       $s5, %hi(D_E0114740)
/* 3FEBE4 E0114104 26B54740 */  addiu     $s5, $s5, %lo(D_E0114740)
/* 3FEBE8 E0114108 0280902D */  daddu     $s2, $s4, $zero
/* 3FEBEC E011410C 8E820004 */  lw        $v0, 4($s4)
/* 3FEBF0 E0114110 0280882D */  daddu     $s1, $s4, $zero
/* 3FEBF4 E0114114 24420001 */  addiu     $v0, $v0, 1
/* 3FEBF8 E0114118 AE820004 */  sw        $v0, 4($s4)
.LE011411C:
/* 3FEBFC E011411C 922300FA */  lbu       $v1, 0xfa($s1)
/* 3FEC00 E0114120 8230013C */  lb        $s0, 0x13c($s1)
/* 3FEC04 E0114124 2C620006 */  sltiu     $v0, $v1, 6
/* 3FEC08 E0114128 10400050 */  beqz      $v0, .LE011426C
/* 3FEC0C E011412C 0000982D */   daddu    $s3, $zero, $zero
/* 3FEC10 E0114130 00031080 */  sll       $v0, $v1, 2
/* 3FEC14 E0114134 3C01E011 */  lui       $at, %hi(jtbl_E0114750)
/* 3FEC18 E0114138 00220821 */  addu      $at, $at, $v0
/* 3FEC1C E011413C 8C224750 */  lw        $v0, %lo(jtbl_E0114750)($at)
/* 3FEC20 E0114140 00400008 */  jr        $v0
/* 3FEC24 E0114144 00000000 */   nop
glabel LE0114148_3FEC28
/* 3FEC28 E0114148 24020001 */  addiu     $v0, $zero, 1
/* 3FEC2C E011414C A2220105 */  sb        $v0, 0x105($s1)
glabel LE0114150_3FEC30
/* 3FEC30 E0114150 080450B5 */  j         .LE01142D4
/* 3FEC34 E0114154 24130001 */   addiu    $s3, $zero, 1
glabel LE0114158_3FEC38
/* 3FEC38 E0114158 06010002 */  bgez      $s0, .LE0114164
/* 3FEC3C E011415C 0200102D */   daddu    $v0, $s0, $zero
/* 3FEC40 E0114160 26020003 */  addiu     $v0, $s0, 3
.LE0114164:
/* 3FEC44 E0114164 00021083 */  sra       $v0, $v0, 2
/* 3FEC48 E0114168 00021080 */  sll       $v0, $v0, 2
/* 3FEC4C E011416C 02021023 */  subu      $v0, $s0, $v0
/* 3FEC50 E0114170 00551021 */  addu      $v0, $v0, $s5
/* 3FEC54 E0114174 00101880 */  sll       $v1, $s0, 2
/* 3FEC58 E0114178 00701821 */  addu      $v1, $v1, $s0
/* 3FEC5C E011417C 00031840 */  sll       $v1, $v1, 1
/* 3FEC60 E0114180 90420000 */  lbu       $v0, ($v0)
/* 3FEC64 E0114184 44836000 */  mtc1      $v1, $f12
/* 3FEC68 E0114188 00000000 */  nop
/* 3FEC6C E011418C 46806320 */  cvt.s.w   $f12, $f12
/* 3FEC70 E0114190 0C080140 */  jal       func_E0200500
/* 3FEC74 E0114194 A2220105 */   sb       $v0, 0x105($s1)
/* 3FEC78 E0114198 C64200B8 */  lwc1      $f2, 0xb8($s2)
/* 3FEC7C E011419C 46001080 */  add.s     $f2, $f2, $f0
/* 3FEC80 E01141A0 2A020024 */  slti      $v0, $s0, 0x24
/* 3FEC84 E01141A4 1440004B */  bnez      $v0, .LE01142D4
/* 3FEC88 E01141A8 E64200B8 */   swc1     $f2, 0xb8($s2)
/* 3FEC8C E01141AC 080450B4 */  j         .LE01142D0
/* 3FEC90 E01141B0 24130001 */   addiu    $s3, $zero, 1
glabel LE01141B4_3FEC94
/* 3FEC94 E01141B4 06010002 */  bgez      $s0, .LE01141C0
/* 3FEC98 E01141B8 0200102D */   daddu    $v0, $s0, $zero
/* 3FEC9C E01141BC 26020003 */  addiu     $v0, $s0, 3
.LE01141C0:
/* 3FECA0 E01141C0 00021083 */  sra       $v0, $v0, 2
/* 3FECA4 E01141C4 00021080 */  sll       $v0, $v0, 2
/* 3FECA8 E01141C8 02021023 */  subu      $v0, $s0, $v0
/* 3FECAC E01141CC 00551021 */  addu      $v0, $v0, $s5
/* 3FECB0 E01141D0 00101880 */  sll       $v1, $s0, 2
/* 3FECB4 E01141D4 00701821 */  addu      $v1, $v1, $s0
/* 3FECB8 E01141D8 00031880 */  sll       $v1, $v1, 2
/* 3FECBC E01141DC 90420000 */  lbu       $v0, ($v0)
/* 3FECC0 E01141E0 44836000 */  mtc1      $v1, $f12
/* 3FECC4 E01141E4 00000000 */  nop
/* 3FECC8 E01141E8 46806320 */  cvt.s.w   $f12, $f12
/* 3FECCC E01141EC 0C080140 */  jal       func_E0200500
/* 3FECD0 E01141F0 A2220105 */   sb       $v0, 0x105($s1)
/* 3FECD4 E01141F4 46000000 */  add.s     $f0, $f0, $f0
/* 3FECD8 E01141F8 24130001 */  addiu     $s3, $zero, 1
/* 3FECDC E01141FC 2A020009 */  slti      $v0, $s0, 9
/* 3FECE0 E0114200 14400034 */  bnez      $v0, .LE01142D4
/* 3FECE4 E0114204 E6400110 */   swc1     $f0, 0x110($s2)
/* 3FECE8 E0114208 080450B4 */  j         .LE01142D0
/* 3FECEC E011420C AE400110 */   sw       $zero, 0x110($s2)
glabel LE0114210_3FECF0
/* 3FECF0 E0114210 06010002 */  bgez      $s0, .LE011421C
/* 3FECF4 E0114214 0200102D */   daddu    $v0, $s0, $zero
/* 3FECF8 E0114218 26020003 */  addiu     $v0, $s0, 3
.LE011421C:
/* 3FECFC E011421C 00021083 */  sra       $v0, $v0, 2
/* 3FED00 E0114220 00021080 */  sll       $v0, $v0, 2
/* 3FED04 E0114224 02021023 */  subu      $v0, $s0, $v0
/* 3FED08 E0114228 00551021 */  addu      $v0, $v0, $s5
/* 3FED0C E011422C 00101880 */  sll       $v1, $s0, 2
/* 3FED10 E0114230 00701821 */  addu      $v1, $v1, $s0
/* 3FED14 E0114234 00031880 */  sll       $v1, $v1, 2
/* 3FED18 E0114238 90420000 */  lbu       $v0, ($v0)
/* 3FED1C E011423C 44836000 */  mtc1      $v1, $f12
/* 3FED20 E0114240 00000000 */  nop
/* 3FED24 E0114244 46806320 */  cvt.s.w   $f12, $f12
/* 3FED28 E0114248 0C080140 */  jal       func_E0200500
/* 3FED2C E011424C A2220105 */   sb       $v0, 0x105($s1)
/* 3FED30 E0114250 3C014080 */  lui       $at, 0x4080
/* 3FED34 E0114254 44811000 */  mtc1      $at, $f2
/* 3FED38 E0114258 00000000 */  nop
/* 3FED3C E011425C 46020002 */  mul.s     $f0, $f0, $f2
/* 3FED40 E0114260 00000000 */  nop
/* 3FED44 E0114264 080450B0 */  j         .LE01142C0
/* 3FED48 E0114268 2A020009 */   slti     $v0, $s0, 9
.LE011426C:
glabel LE011426C_3FED4C
/* 3FED4C E011426C 06010002 */  bgez      $s0, .LE0114278
/* 3FED50 E0114270 0200102D */   daddu    $v0, $s0, $zero
/* 3FED54 E0114274 26020003 */  addiu     $v0, $s0, 3
.LE0114278:
/* 3FED58 E0114278 00021083 */  sra       $v0, $v0, 2
/* 3FED5C E011427C 00021080 */  sll       $v0, $v0, 2
/* 3FED60 E0114280 02021023 */  subu      $v0, $s0, $v0
/* 3FED64 E0114284 00551021 */  addu      $v0, $v0, $s5
/* 3FED68 E0114288 00101880 */  sll       $v1, $s0, 2
/* 3FED6C E011428C 00701821 */  addu      $v1, $v1, $s0
/* 3FED70 E0114290 90420000 */  lbu       $v0, ($v0)
/* 3FED74 E0114294 44836000 */  mtc1      $v1, $f12
/* 3FED78 E0114298 00000000 */  nop
/* 3FED7C E011429C 46806320 */  cvt.s.w   $f12, $f12
/* 3FED80 E01142A0 0C080140 */  jal       func_E0200500
/* 3FED84 E01142A4 A2220105 */   sb       $v0, 0x105($s1)
/* 3FED88 E01142A8 3C014140 */  lui       $at, 0x4140
/* 3FED8C E01142AC 44811000 */  mtc1      $at, $f2
/* 3FED90 E01142B0 00000000 */  nop
/* 3FED94 E01142B4 46020002 */  mul.s     $f0, $f0, $f2
/* 3FED98 E01142B8 00000000 */  nop
/* 3FED9C E01142BC 2A020024 */  slti      $v0, $s0, 0x24
.LE01142C0:
/* 3FEDA0 E01142C0 14400004 */  bnez      $v0, .LE01142D4
/* 3FEDA4 E01142C4 E6400110 */   swc1     $f0, 0x110($s2)
/* 3FEDA8 E01142C8 24130001 */  addiu     $s3, $zero, 1
/* 3FEDAC E01142CC AE400110 */  sw        $zero, 0x110($s2)
.LE01142D0:
/* 3FEDB0 E01142D0 A220013C */  sb        $zero, 0x13c($s1)
.LE01142D4:
/* 3FEDB4 E01142D4 9222013C */  lbu       $v0, 0x13c($s1)
/* 3FEDB8 E01142D8 24420001 */  addiu     $v0, $v0, 1
/* 3FEDBC E01142DC 1260000A */  beqz      $s3, .LE0114308
/* 3FEDC0 E01142E0 A222013C */   sb       $v0, 0x13c($s1)
/* 3FEDC4 E01142E4 8E430008 */  lw        $v1, 8($s2)
/* 3FEDC8 E01142E8 30620002 */  andi      $v0, $v1, 2
/* 3FEDCC E01142EC 10400006 */  beqz      $v0, .LE0114308
/* 3FEDD0 E01142F0 2402FFFD */   addiu    $v0, $zero, -3
/* 3FEDD4 E01142F4 00621024 */  and       $v0, $v1, $v0
/* 3FEDD8 E01142F8 AE420008 */  sw        $v0, 8($s2)
/* 3FEDDC E01142FC 922200EF */  lbu       $v0, 0xef($s1)
/* 3FEDE0 E0114300 A220013C */  sb        $zero, 0x13c($s1)
/* 3FEDE4 E0114304 A22200FA */  sb        $v0, 0xfa($s1)
.LE0114308:
/* 3FEDE8 E0114308 26310001 */  addiu     $s1, $s1, 1
/* 3FEDEC E011430C 2682000B */  addiu     $v0, $s4, 0xb
/* 3FEDF0 E0114310 0222102A */  slt       $v0, $s1, $v0
/* 3FEDF4 E0114314 1440FF81 */  bnez      $v0, .LE011411C
/* 3FEDF8 E0114318 26520004 */   addiu    $s2, $s2, 4
/* 3FEDFC E011431C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 3FEE00 E0114320 8FB50024 */  lw        $s5, 0x24($sp)
/* 3FEE04 E0114324 8FB40020 */  lw        $s4, 0x20($sp)
/* 3FEE08 E0114328 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3FEE0C E011432C 8FB20018 */  lw        $s2, 0x18($sp)
/* 3FEE10 E0114330 8FB10014 */  lw        $s1, 0x14($sp)
/* 3FEE14 E0114334 8FB00010 */  lw        $s0, 0x10($sp)
/* 3FEE18 E0114338 03E00008 */  jr        $ra
/* 3FEE1C E011433C 27BD0030 */   addiu    $sp, $sp, 0x30
