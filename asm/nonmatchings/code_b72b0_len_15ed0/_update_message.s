.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _update_message
/* B9F98 80123898 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9F9C 8012389C AFB00010 */  sw        $s0, 0x10($sp)
/* B9FA0 801238A0 0080802D */  daddu     $s0, $a0, $zero
/* B9FA4 801238A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* B9FA8 801238A8 AFB10014 */  sw        $s1, 0x14($sp)
/* B9FAC 801238AC 96020452 */  lhu       $v0, 0x452($s0)
/* B9FB0 801238B0 24420001 */  addiu     $v0, $v0, 1
/* B9FB4 801238B4 A6020452 */  sh        $v0, 0x452($s0)
/* B9FB8 801238B8 3042FFFF */  andi      $v0, $v0, 0xffff
/* B9FBC 801238BC 2C420E10 */  sltiu     $v0, $v0, 0xe10
/* B9FC0 801238C0 50400001 */  beql      $v0, $zero, .L801238C8
/* B9FC4 801238C4 A6000452 */   sh       $zero, 0x452($s0)
.L801238C8:
/* B9FC8 801238C8 8602050A */  lh        $v0, 0x50a($s0)
/* B9FCC 801238CC 3C014064 */  lui       $at, 0x4064
/* B9FD0 801238D0 44811800 */  mtc1      $at, $f3
/* B9FD4 801238D4 44801000 */  mtc1      $zero, $f2
/* B9FD8 801238D8 44820000 */  mtc1      $v0, $f0
/* B9FDC 801238DC 00000000 */  nop       
/* B9FE0 801238E0 46800020 */  cvt.s.w   $f0, $f0
/* B9FE4 801238E4 46000021 */  cvt.d.s   $f0, $f0
/* B9FE8 801238E8 46220001 */  sub.d     $f0, $f0, $f2
/* B9FEC 801238EC 3C018015 */  lui       $at, %hi(D_80150370)
/* B9FF0 801238F0 D4220370 */  ldc1      $f2, %lo(D_80150370)($at)
/* B9FF4 801238F4 3C014050 */  lui       $at, 0x4050
/* B9FF8 801238F8 44812800 */  mtc1      $at, $f5
/* B9FFC 801238FC 44802000 */  mtc1      $zero, $f4
/* BA000 80123900 46220003 */  div.d     $f0, $f0, $f2
/* BA004 80123904 46240000 */  add.d     $f0, $f0, $f4
/* BA008 80123908 46200120 */  cvt.s.d   $f4, $f0
/* BA00C 8012390C 3C014014 */  lui       $at, 0x4014
/* BA010 80123910 44810800 */  mtc1      $at, $f1
/* BA014 80123914 44800000 */  mtc1      $zero, $f0
/* BA018 80123918 460020A1 */  cvt.d.s   $f2, $f4
/* BA01C 8012391C 4620103C */  c.lt.d    $f2, $f0
/* BA020 80123920 00000000 */  nop       
/* BA024 80123924 45000005 */  bc1f      .L8012393C
/* BA028 80123928 00000000 */   nop      
/* BA02C 8012392C 3C0140A0 */  lui       $at, 0x40a0
/* BA030 80123930 44812000 */  mtc1      $at, $f4
/* BA034 80123934 08048E57 */  j         .L8012395C
/* BA038 80123938 00000000 */   nop      
.L8012393C:
/* BA03C 8012393C 3C018015 */  lui       $at, %hi(D_80150378)
/* BA040 80123940 D4200378 */  ldc1      $f0, %lo(D_80150378)($at)
/* BA044 80123944 4622003C */  c.lt.d    $f0, $f2
/* BA048 80123948 00000000 */  nop       
/* BA04C 8012394C 45000003 */  bc1f      .L8012395C
/* BA050 80123950 00000000 */   nop      
/* BA054 80123954 3C0142F4 */  lui       $at, 0x42f4
/* BA058 80123958 44812000 */  mtc1      $at, $f4
.L8012395C:
/* BA05C 8012395C 3C014F00 */  lui       $at, 0x4f00
/* BA060 80123960 44810000 */  mtc1      $at, $f0
/* BA064 80123964 00000000 */  nop       
/* BA068 80123968 4604003E */  c.le.s    $f0, $f4
/* BA06C 8012396C 00000000 */  nop       
/* BA070 80123970 45010005 */  bc1t      .L80123988
/* BA074 80123974 2604051A */   addiu    $a0, $s0, 0x51a
/* BA078 80123978 4600218D */  trunc.w.s $f6, $f4
/* BA07C 8012397C 44033000 */  mfc1      $v1, $f6
/* BA080 80123980 08048E69 */  j         .L801239A4
/* BA084 80123984 A0830000 */   sb       $v1, ($a0)
.L80123988:
/* BA088 80123988 46002001 */  sub.s     $f0, $f4, $f0
/* BA08C 8012398C 3C028000 */  lui       $v0, 0x8000
/* BA090 80123990 4600018D */  trunc.w.s $f6, $f0
/* BA094 80123994 44033000 */  mfc1      $v1, $f6
/* BA098 80123998 00000000 */  nop       
/* BA09C 8012399C 00621825 */  or        $v1, $v1, $v0
/* BA0A0 801239A0 A0830000 */  sb        $v1, ($a0)
.L801239A4:
/* BA0A4 801239A4 8E0604FC */  lw        $a2, 0x4fc($s0)
/* BA0A8 801239A8 30C20040 */  andi      $v0, $a2, 0x40
/* BA0AC 801239AC 144001F1 */  bnez      $v0, .L80124174
/* BA0B0 801239B0 0000882D */   daddu    $s1, $zero, $zero
/* BA0B4 801239B4 30C20030 */  andi      $v0, $a2, 0x30
/* BA0B8 801239B8 144000F3 */  bnez      $v0, .L80123D88
/* BA0BC 801239BC 30C20020 */   andi     $v0, $a2, 0x20
/* BA0C0 801239C0 920304F8 */  lbu       $v1, 0x4f8($s0)
/* BA0C4 801239C4 24020007 */  addiu     $v0, $zero, 7
/* BA0C8 801239C8 1062008D */  beq       $v1, $v0, .L80123C00
/* BA0CC 801239CC 34078000 */   ori      $a3, $zero, 0x8000
/* BA0D0 801239D0 28620008 */  slti      $v0, $v1, 8
/* BA0D4 801239D4 10400005 */  beqz      $v0, .L801239EC
/* BA0D8 801239D8 24020005 */   addiu    $v0, $zero, 5
/* BA0DC 801239DC 1062000A */  beq       $v1, $v0, .L80123A08
/* BA0E0 801239E0 3C020008 */   lui      $v0, 8
/* BA0E4 801239E4 08048F72 */  j         .L80123DC8
/* BA0E8 801239E8 00000000 */   nop      
.L801239EC:
/* BA0EC 801239EC 24020008 */  addiu     $v0, $zero, 8
/* BA0F0 801239F0 106200D9 */  beq       $v1, $v0, .L80123D58
/* BA0F4 801239F4 2402000C */   addiu    $v0, $zero, 0xc
/* BA0F8 801239F8 1062004F */  beq       $v1, $v0, .L80123B38
/* BA0FC 801239FC 00000000 */   nop      
/* BA100 80123A00 08048F72 */  j         .L80123DC8
/* BA104 80123A04 00000000 */   nop      
.L80123A08:
/* BA108 80123A08 00C21024 */  and       $v0, $a2, $v0
/* BA10C 80123A0C 54400001 */  bnel      $v0, $zero, .L80123A14
/* BA110 80123A10 34078004 */   ori      $a3, $zero, 0x8004
.L80123A14:
/* BA114 80123A14 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* BA118 80123A18 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* BA11C 80123A1C 8C640000 */  lw        $a0, ($v1)
/* BA120 80123A20 8C850010 */  lw        $a1, 0x10($a0)
/* BA124 80123A24 00E51024 */  and       $v0, $a3, $a1
/* BA128 80123A28 14400005 */  bnez      $v0, .L80123A40
/* BA12C 80123A2C 00000000 */   nop      
/* BA130 80123A30 8C820000 */  lw        $v0, ($a0)
/* BA134 80123A34 30424000 */  andi      $v0, $v0, 0x4000
/* BA138 80123A38 1040002F */  beqz      $v0, .L80123AF8
/* BA13C 80123A3C 30A22000 */   andi     $v0, $a1, 0x2000
.L80123A40:
/* BA140 80123A40 8E0404FC */  lw        $a0, 0x4fc($s0)
/* BA144 80123A44 24020004 */  addiu     $v0, $zero, 4
/* BA148 80123A48 A20204F8 */  sb        $v0, 0x4f8($s0)
/* BA14C 80123A4C A600000E */  sh        $zero, 0xe($s0)
/* BA150 80123A50 8C630000 */  lw        $v1, ($v1)
/* BA154 80123A54 34820004 */  ori       $v0, $a0, 4
/* BA158 80123A58 AE0204FC */  sw        $v0, 0x4fc($s0)
/* BA15C 80123A5C 8C620010 */  lw        $v0, 0x10($v1)
/* BA160 80123A60 30428004 */  andi      $v0, $v0, 0x8004
/* BA164 80123A64 10400003 */  beqz      $v0, .L80123A74
/* BA168 80123A68 00000000 */   nop      
/* BA16C 80123A6C 08048EB7 */  j         .L80123ADC
/* BA170 80123A70 24110001 */   addiu    $s1, $zero, 1
.L80123A74:
/* BA174 80123A74 9603000C */  lhu       $v1, 0xc($s0)
/* BA178 80123A78 8E020000 */  lw        $v0, ($s0)
/* BA17C 80123A7C 00431021 */  addu      $v0, $v0, $v1
/* BA180 80123A80 90430000 */  lbu       $v1, ($v0)
/* BA184 80123A84 240200FD */  addiu     $v0, $zero, 0xfd
/* BA188 80123A88 1062000F */  beq       $v1, $v0, .L80123AC8
/* BA18C 80123A8C 34820104 */   ori      $v0, $a0, 0x104
/* BA190 80123A90 92030455 */  lbu       $v1, 0x455($s0)
/* BA194 80123A94 14600008 */  bnez      $v1, .L80123AB8
/* BA198 80123A98 AE0204FC */   sw       $v0, 0x4fc($s0)
/* BA19C 80123A9C 9603000C */  lhu       $v1, 0xc($s0)
/* BA1A0 80123AA0 8E020000 */  lw        $v0, ($s0)
/* BA1A4 80123AA4 00431021 */  addu      $v0, $v0, $v1
/* BA1A8 80123AA8 90430000 */  lbu       $v1, ($v0)
/* BA1AC 80123AAC 240200C3 */  addiu     $v0, $zero, 0xc3
/* BA1B0 80123AB0 5062000B */  beql      $v1, $v0, .L80123AE0
/* BA1B4 80123AB4 240400CC */   addiu    $a0, $zero, 0xcc
.L80123AB8:
/* BA1B8 80123AB8 34820184 */  ori       $v0, $a0, 0x184
/* BA1BC 80123ABC AE0204FC */  sw        $v0, 0x4fc($s0)
/* BA1C0 80123AC0 08048EB8 */  j         .L80123AE0
/* BA1C4 80123AC4 240400CC */   addiu    $a0, $zero, 0xcc
.L80123AC8:
/* BA1C8 80123AC8 92020508 */  lbu       $v0, 0x508($s0)
/* BA1CC 80123ACC 2442FFFF */  addiu     $v0, $v0, -1
/* BA1D0 80123AD0 2C420004 */  sltiu     $v0, $v0, 4
/* BA1D4 80123AD4 104000BC */  beqz      $v0, .L80123DC8
/* BA1D8 80123AD8 00000000 */   nop      
.L80123ADC:
/* BA1DC 80123ADC 240400C9 */  addiu     $a0, $zero, 0xc9
.L80123AE0:
/* BA1E0 80123AE0 0000282D */  daddu     $a1, $zero, $zero
/* BA1E4 80123AE4 00A0302D */  daddu     $a2, $a1, $zero
/* BA1E8 80123AE8 0C0526AE */  jal       _play_sound
/* BA1EC 80123AEC 00A0382D */   daddu    $a3, $a1, $zero
/* BA1F0 80123AF0 08048F72 */  j         .L80123DC8
/* BA1F4 80123AF4 00000000 */   nop      
.L80123AF8:
/* BA1F8 80123AF8 104000B3 */  beqz      $v0, .L80123DC8
/* BA1FC 80123AFC 3C020004 */   lui      $v0, 4
/* BA200 80123B00 00C21024 */  and       $v0, $a2, $v0
/* BA204 80123B04 144000B0 */  bnez      $v0, .L80123DC8
/* BA208 80123B08 00000000 */   nop      
/* BA20C 80123B0C 92020486 */  lbu       $v0, 0x486($s0)
/* BA210 80123B10 104000AD */  beqz      $v0, .L80123DC8
/* BA214 80123B14 240400CD */   addiu    $a0, $zero, 0xcd
/* BA218 80123B18 0000282D */  daddu     $a1, $zero, $zero
/* BA21C 80123B1C 00A0302D */  daddu     $a2, $a1, $zero
/* BA220 80123B20 92020486 */  lbu       $v0, 0x486($s0)
/* BA224 80123B24 2403000B */  addiu     $v1, $zero, 0xb
/* BA228 80123B28 A20304F8 */  sb        $v1, 0x4f8($s0)
/* BA22C 80123B2C A60004CC */  sh        $zero, 0x4cc($s0)
/* BA230 80123B30 08048EF2 */  j         .L80123BC8
/* BA234 80123B34 2442FFFF */   addiu    $v0, $v0, -1
.L80123B38:
/* BA238 80123B38 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA23C 80123B3C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA240 80123B40 8C430010 */  lw        $v1, 0x10($v0)
/* BA244 80123B44 30624000 */  andi      $v0, $v1, 0x4000
/* BA248 80123B48 10400008 */  beqz      $v0, .L80123B6C
/* BA24C 80123B4C 240400CC */   addiu    $a0, $zero, 0xcc
/* BA250 80123B50 0000282D */  daddu     $a1, $zero, $zero
/* BA254 80123B54 00A0302D */  daddu     $a2, $a1, $zero
/* BA258 80123B58 92020486 */  lbu       $v0, 0x486($s0)
/* BA25C 80123B5C 2403000B */  addiu     $v1, $zero, 0xb
/* BA260 80123B60 A20304F8 */  sb        $v1, 0x4f8($s0)
/* BA264 80123B64 08048EF2 */  j         .L80123BC8
/* BA268 80123B68 A60004CC */   sh       $zero, 0x4cc($s0)
.L80123B6C:
/* BA26C 80123B6C 30622000 */  andi      $v0, $v1, 0x2000
/* BA270 80123B70 1040000C */  beqz      $v0, .L80123BA4
/* BA274 80123B74 30628000 */   andi     $v0, $v1, 0x8000
/* BA278 80123B78 92020487 */  lbu       $v0, 0x487($s0)
/* BA27C 80123B7C 10400092 */  beqz      $v0, .L80123DC8
/* BA280 80123B80 240400CD */   addiu    $a0, $zero, 0xcd
/* BA284 80123B84 0000282D */  daddu     $a1, $zero, $zero
/* BA288 80123B88 00A0302D */  daddu     $a2, $a1, $zero
/* BA28C 80123B8C 92020487 */  lbu       $v0, 0x487($s0)
/* BA290 80123B90 2403000B */  addiu     $v1, $zero, 0xb
/* BA294 80123B94 A20304F8 */  sb        $v1, 0x4f8($s0)
/* BA298 80123B98 A60004CC */  sh        $zero, 0x4cc($s0)
/* BA29C 80123B9C 08048EF2 */  j         .L80123BC8
/* BA2A0 80123BA0 2442FFFF */   addiu    $v0, $v0, -1
.L80123BA4:
/* BA2A4 80123BA4 10400088 */  beqz      $v0, .L80123DC8
/* BA2A8 80123BA8 240400CE */   addiu    $a0, $zero, 0xce
/* BA2AC 80123BAC 0000282D */  daddu     $a1, $zero, $zero
/* BA2B0 80123BB0 00A0302D */  daddu     $a2, $a1, $zero
/* BA2B4 80123BB4 92020487 */  lbu       $v0, 0x487($s0)
/* BA2B8 80123BB8 2403000B */  addiu     $v1, $zero, 0xb
/* BA2BC 80123BBC A20304F8 */  sb        $v1, 0x4f8($s0)
/* BA2C0 80123BC0 A60004CC */  sh        $zero, 0x4cc($s0)
/* BA2C4 80123BC4 24420001 */  addiu     $v0, $v0, 1
.L80123BC8:
/* BA2C8 80123BC8 A2020487 */  sb        $v0, 0x487($s0)
/* BA2CC 80123BCC 304200FF */  andi      $v0, $v0, 0xff
/* BA2D0 80123BD0 00021040 */  sll       $v0, $v0, 1
/* BA2D4 80123BD4 02021021 */  addu      $v0, $s0, $v0
/* BA2D8 80123BD8 94430488 */  lhu       $v1, 0x488($v0)
/* BA2DC 80123BDC 8E020460 */  lw        $v0, 0x460($s0)
/* BA2E0 80123BE0 00A0382D */  daddu     $a3, $a1, $zero
/* BA2E4 80123BE4 00431023 */  subu      $v0, $v0, $v1
/* BA2E8 80123BE8 04420001 */  bltzl     $v0, .L80123BF0
/* BA2EC 80123BEC 00021023 */   negu     $v0, $v0
.L80123BF0:
/* BA2F0 80123BF0 0C0526AE */  jal       _play_sound
/* BA2F4 80123BF4 A60204C8 */   sh       $v0, 0x4c8($s0)
/* BA2F8 80123BF8 08048F72 */  j         .L80123DC8
/* BA2FC 80123BFC 00000000 */   nop      
.L80123C00:
/* BA300 80123C00 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA304 80123C04 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA308 80123C08 8C440010 */  lw        $a0, 0x10($v0)
/* BA30C 80123C0C 30828000 */  andi      $v0, $a0, 0x8000
/* BA310 80123C10 1040000E */  beqz      $v0, .L80123C4C
/* BA314 80123C14 0000282D */   daddu    $a1, $zero, $zero
/* BA318 80123C18 240400C9 */  addiu     $a0, $zero, 0xc9
/* BA31C 80123C1C 00A0302D */  daddu     $a2, $a1, $zero
/* BA320 80123C20 00A0382D */  daddu     $a3, $a1, $zero
/* BA324 80123C24 24020001 */  addiu     $v0, $zero, 1
/* BA328 80123C28 A20204E9 */  sb        $v0, 0x4e9($s0)
/* BA32C 80123C2C 24020004 */  addiu     $v0, $zero, 4
/* BA330 80123C30 A20204F8 */  sb        $v0, 0x4f8($s0)
/* BA334 80123C34 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BA338 80123C38 3C030002 */  lui       $v1, 2
/* BA33C 80123C3C A20004ED */  sb        $zero, 0x4ed($s0)
/* BA340 80123C40 00431025 */  or        $v0, $v0, $v1
/* BA344 80123C44 08048F50 */  j         .L80123D40
/* BA348 80123C48 AE0204FC */   sw       $v0, 0x4fc($s0)
.L80123C4C:
/* BA34C 80123C4C 920504EA */  lbu       $a1, 0x4ea($s0)
/* BA350 80123C50 240200FF */  addiu     $v0, $zero, 0xff
/* BA354 80123C54 30A300FF */  andi      $v1, $a1, 0xff
/* BA358 80123C58 10620019 */  beq       $v1, $v0, .L80123CC0
/* BA35C 80123C5C 30824000 */   andi     $v0, $a0, 0x4000
/* BA360 80123C60 10400017 */  beqz      $v0, .L80123CC0
/* BA364 80123C64 00000000 */   nop      
/* BA368 80123C68 920204CE */  lbu       $v0, 0x4ce($s0)
/* BA36C 80123C6C 0062102B */  sltu      $v0, $v1, $v0
/* BA370 80123C70 54400003 */  bnel      $v0, $zero, .L80123C80
/* BA374 80123C74 A20504EE */   sb       $a1, 0x4ee($s0)
/* BA378 80123C78 920204E8 */  lbu       $v0, 0x4e8($s0)
/* BA37C 80123C7C A20204EE */  sb        $v0, 0x4ee($s0)
.L80123C80:
/* BA380 80123C80 240400CA */  addiu     $a0, $zero, 0xca
/* BA384 80123C84 0000282D */  daddu     $a1, $zero, $zero
/* BA388 80123C88 00A0302D */  daddu     $a2, $a1, $zero
/* BA38C 80123C8C 920304EA */  lbu       $v1, 0x4ea($s0)
/* BA390 80123C90 24020001 */  addiu     $v0, $zero, 1
/* BA394 80123C94 A20204E9 */  sb        $v0, 0x4e9($s0)
/* BA398 80123C98 24020004 */  addiu     $v0, $zero, 4
/* BA39C 80123C9C A20204F8 */  sb        $v0, 0x4f8($s0)
/* BA3A0 80123CA0 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BA3A4 80123CA4 00A0382D */  daddu     $a3, $a1, $zero
/* BA3A8 80123CA8 A20004ED */  sb        $zero, 0x4ed($s0)
/* BA3AC 80123CAC A20304E8 */  sb        $v1, 0x4e8($s0)
/* BA3B0 80123CB0 3C030002 */  lui       $v1, 2
/* BA3B4 80123CB4 00431025 */  or        $v0, $v0, $v1
/* BA3B8 80123CB8 08048F50 */  j         .L80123D40
/* BA3BC 80123CBC AE0204FC */   sw       $v0, 0x4fc($s0)
.L80123CC0:
/* BA3C0 80123CC0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA3C4 80123CC4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA3C8 80123CC8 8C430020 */  lw        $v1, 0x20($v0)
/* BA3CC 80123CCC 3C020002 */  lui       $v0, 2
/* BA3D0 80123CD0 00621024 */  and       $v0, $v1, $v0
/* BA3D4 80123CD4 1040000B */  beqz      $v0, .L80123D04
/* BA3D8 80123CD8 3C020001 */   lui      $v0, 1
/* BA3DC 80123CDC 920204CE */  lbu       $v0, 0x4ce($s0)
/* BA3E0 80123CE0 920304E8 */  lbu       $v1, 0x4e8($s0)
/* BA3E4 80123CE4 2442FFFF */  addiu     $v0, $v0, -1
/* BA3E8 80123CE8 10620017 */  beq       $v1, $v0, .L80123D48
/* BA3EC 80123CEC 240400C7 */   addiu    $a0, $zero, 0xc7
/* BA3F0 80123CF0 0000282D */  daddu     $a1, $zero, $zero
/* BA3F4 80123CF4 00A0302D */  daddu     $a2, $a1, $zero
/* BA3F8 80123CF8 00A0382D */  daddu     $a3, $a1, $zero
/* BA3FC 80123CFC 08048F4B */  j         .L80123D2C
/* BA400 80123D00 24620001 */   addiu    $v0, $v1, 1
.L80123D04:
/* BA404 80123D04 00621024 */  and       $v0, $v1, $v0
/* BA408 80123D08 1040000F */  beqz      $v0, .L80123D48
/* BA40C 80123D0C 00000000 */   nop      
/* BA410 80123D10 920204E8 */  lbu       $v0, 0x4e8($s0)
/* BA414 80123D14 1040000C */  beqz      $v0, .L80123D48
/* BA418 80123D18 240400C7 */   addiu    $a0, $zero, 0xc7
/* BA41C 80123D1C 0000282D */  daddu     $a1, $zero, $zero
/* BA420 80123D20 00A0302D */  daddu     $a2, $a1, $zero
/* BA424 80123D24 00A0382D */  daddu     $a3, $a1, $zero
/* BA428 80123D28 2442FFFF */  addiu     $v0, $v0, -1
.L80123D2C:
/* BA42C 80123D2C A20204EC */  sb        $v0, 0x4ec($s0)
/* BA430 80123D30 24020008 */  addiu     $v0, $zero, 8
/* BA434 80123D34 A20204F8 */  sb        $v0, 0x4f8($s0)
/* BA438 80123D38 24020001 */  addiu     $v0, $zero, 1
/* BA43C 80123D3C A20204ED */  sb        $v0, 0x4ed($s0)
.L80123D40:
/* BA440 80123D40 0C0526AE */  jal       _play_sound
/* BA444 80123D44 00000000 */   nop      
.L80123D48:
/* BA448 80123D48 920304F8 */  lbu       $v1, 0x4f8($s0)
/* BA44C 80123D4C 24020008 */  addiu     $v0, $zero, 8
/* BA450 80123D50 1462001D */  bne       $v1, $v0, .L80123DC8
/* BA454 80123D54 00000000 */   nop      
.L80123D58:
/* BA458 80123D58 920204ED */  lbu       $v0, 0x4ed($s0)
/* BA45C 80123D5C 24420001 */  addiu     $v0, $v0, 1
/* BA460 80123D60 A20204ED */  sb        $v0, 0x4ed($s0)
/* BA464 80123D64 304200FF */  andi      $v0, $v0, 0xff
/* BA468 80123D68 2C420005 */  sltiu     $v0, $v0, 5
/* BA46C 80123D6C 14400016 */  bnez      $v0, .L80123DC8
/* BA470 80123D70 24020007 */   addiu    $v0, $zero, 7
/* BA474 80123D74 920304EC */  lbu       $v1, 0x4ec($s0)
/* BA478 80123D78 A20204F8 */  sb        $v0, 0x4f8($s0)
/* BA47C 80123D7C A20304E8 */  sb        $v1, 0x4e8($s0)
/* BA480 80123D80 08048F72 */  j         .L80123DC8
/* BA484 80123D84 A20304EE */   sb       $v1, 0x4ee($s0)
.L80123D88:
/* BA488 80123D88 1440000F */  bnez      $v0, .L80123DC8
/* BA48C 80123D8C 24020005 */   addiu    $v0, $zero, 5
/* BA490 80123D90 920304F8 */  lbu       $v1, 0x4f8($s0)
/* BA494 80123D94 1462000C */  bne       $v1, $v0, .L80123DC8
/* BA498 80123D98 00000000 */   nop      
/* BA49C 80123D9C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA4A0 80123DA0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA4A4 80123DA4 8C420010 */  lw        $v0, 0x10($v0)
/* BA4A8 80123DA8 30428000 */  andi      $v0, $v0, 0x8000
/* BA4AC 80123DAC 10400006 */  beqz      $v0, .L80123DC8
/* BA4B0 80123DB0 24020004 */   addiu    $v0, $zero, 4
/* BA4B4 80123DB4 8E0304FC */  lw        $v1, 0x4fc($s0)
/* BA4B8 80123DB8 A20204F8 */  sb        $v0, 0x4f8($s0)
/* BA4BC 80123DBC A600000E */  sh        $zero, 0xe($s0)
/* BA4C0 80123DC0 34630004 */  ori       $v1, $v1, 4
/* BA4C4 80123DC4 AE0304FC */  sw        $v1, 0x4fc($s0)
.L80123DC8:
/* BA4C8 80123DC8 8E0304FC */  lw        $v1, 0x4fc($s0)
/* BA4CC 80123DCC 30620004 */  andi      $v0, $v1, 4
/* BA4D0 80123DD0 1040000B */  beqz      $v0, .L80123E00
/* BA4D4 80123DD4 0000282D */   daddu    $a1, $zero, $zero
/* BA4D8 80123DD8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA4DC 80123DDC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA4E0 80123DE0 8C420000 */  lw        $v0, ($v0)
/* BA4E4 80123DE4 30428000 */  andi      $v0, $v0, 0x8000
/* BA4E8 80123DE8 14400006 */  bnez      $v0, .L80123E04
/* BA4EC 80123DEC 0200202D */   daddu    $a0, $s0, $zero
/* BA4F0 80123DF0 2402FFFB */  addiu     $v0, $zero, -5
/* BA4F4 80123DF4 00621024 */  and       $v0, $v1, $v0
/* BA4F8 80123DF8 AE0204FC */  sw        $v0, 0x4fc($s0)
/* BA4FC 80123DFC 0000282D */  daddu     $a1, $zero, $zero
.L80123E00:
/* BA500 80123E00 0200202D */  daddu     $a0, $s0, $zero
.L80123E04:
/* BA504 80123E04 84820474 */  lh        $v0, 0x474($a0)
/* BA508 80123E08 94830474 */  lhu       $v1, 0x474($a0)
/* BA50C 80123E0C 18400003 */  blez      $v0, .L80123E1C
/* BA510 80123E10 24A50001 */   addiu    $a1, $a1, 1
/* BA514 80123E14 2462FFFF */  addiu     $v0, $v1, -1
/* BA518 80123E18 A4820474 */  sh        $v0, 0x474($a0)
.L80123E1C:
/* BA51C 80123E1C 28A20004 */  slti      $v0, $a1, 4
/* BA520 80123E20 1440FFF8 */  bnez      $v0, .L80123E04
/* BA524 80123E24 24840002 */   addiu    $a0, $a0, 2
/* BA528 80123E28 920204F8 */  lbu       $v0, 0x4f8($s0)
/* BA52C 80123E2C 2443FFFF */  addiu     $v1, $v0, -1
/* BA530 80123E30 2C62000E */  sltiu     $v0, $v1, 0xe
/* BA534 80123E34 104000CF */  beqz      $v0, .L80124174
/* BA538 80123E38 00031080 */   sll      $v0, $v1, 2
/* BA53C 80123E3C 3C018015 */  lui       $at, %hi(D_80150380)
/* BA540 80123E40 00220821 */  addu      $at, $at, $v0
/* BA544 80123E44 8C220380 */  lw        $v0, %lo(D_80150380)($at)
/* BA548 80123E48 00400008 */  jr        $v0
/* BA54C 80123E4C 00000000 */   nop      
/* BA550 80123E50 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA554 80123E54 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA558 80123E58 8C430010 */  lw        $v1, 0x10($v0)
/* BA55C 80123E5C 8C420000 */  lw        $v0, ($v0)
/* BA560 80123E60 30638000 */  andi      $v1, $v1, 0x8000
/* BA564 80123E64 30424000 */  andi      $v0, $v0, 0x4000
/* BA568 80123E68 00621825 */  or        $v1, $v1, $v0
/* BA56C 80123E6C 1060000B */  beqz      $v1, .L80123E9C
/* BA570 80123E70 24020001 */   addiu    $v0, $zero, 1
/* BA574 80123E74 8E0304FC */  lw        $v1, 0x4fc($s0)
/* BA578 80123E78 30620030 */  andi      $v0, $v1, 0x30
/* BA57C 80123E7C 14400007 */  bnez      $v0, .L80123E9C
/* BA580 80123E80 24020001 */   addiu    $v0, $zero, 1
/* BA584 80123E84 322200FF */  andi      $v0, $s1, 0xff
/* BA588 80123E88 14400004 */  bnez      $v0, .L80123E9C
/* BA58C 80123E8C 24020001 */   addiu    $v0, $zero, 1
/* BA590 80123E90 34620100 */  ori       $v0, $v1, 0x100
/* BA594 80123E94 AE0204FC */  sw        $v0, 0x4fc($s0)
/* BA598 80123E98 24020001 */  addiu     $v0, $zero, 1
.L80123E9C:
/* BA59C 80123E9C 920304F8 */  lbu       $v1, 0x4f8($s0)
/* BA5A0 80123EA0 9205045F */  lbu       $a1, 0x45f($s0)
/* BA5A4 80123EA4 14620003 */  bne       $v1, $v0, .L80123EB4
/* BA5A8 80123EA8 24020004 */   addiu    $v0, $zero, 4
/* BA5AC 80123EAC 08048FBE */  j         .L80123EF8
/* BA5B0 80123EB0 A20204F8 */   sb       $v0, 0x4f8($s0)
.L80123EB4:
/* BA5B4 80123EB4 8E0304FC */  lw        $v1, 0x4fc($s0)
/* BA5B8 80123EB8 30620100 */  andi      $v0, $v1, 0x100
/* BA5BC 80123EBC 10400003 */  beqz      $v0, .L80123ECC
/* BA5C0 80123EC0 30620004 */   andi     $v0, $v1, 4
/* BA5C4 80123EC4 08048FBE */  j         .L80123EF8
/* BA5C8 80123EC8 2405000C */   addiu    $a1, $zero, 0xc
.L80123ECC:
/* BA5CC 80123ECC 1440000B */  bnez      $v0, .L80123EFC
/* BA5D0 80123ED0 30620030 */   andi     $v0, $v1, 0x30
/* BA5D4 80123ED4 14400009 */  bnez      $v0, .L80123EFC
/* BA5D8 80123ED8 00000000 */   nop      
/* BA5DC 80123EDC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA5E0 80123EE0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA5E4 80123EE4 8C420000 */  lw        $v0, ($v0)
/* BA5E8 80123EE8 30428000 */  andi      $v0, $v0, 0x8000
/* BA5EC 80123EEC 10400003 */  beqz      $v0, .L80123EFC
/* BA5F0 80123EF0 00000000 */   nop      
/* BA5F4 80123EF4 24050006 */  addiu     $a1, $zero, 6
.L80123EF8:
/* BA5F8 80123EF8 A600000E */  sh        $zero, 0xe($s0)
.L80123EFC:
/* BA5FC 80123EFC 9602000E */  lhu       $v0, 0xe($s0)
/* BA600 80123F00 10400005 */  beqz      $v0, .L80123F18
/* BA604 80123F04 2442FFFF */   addiu    $v0, $v0, -1
/* BA608 80123F08 A602000E */  sh        $v0, 0xe($s0)
/* BA60C 80123F0C 3042FFFF */  andi      $v0, $v0, 0xffff
/* BA610 80123F10 14400098 */  bnez      $v0, .L80124174
/* BA614 80123F14 00000000 */   nop      
.L80123F18:
/* BA618 80123F18 0200202D */  daddu     $a0, $s0, $zero
/* BA61C 80123F1C 0C04915C */  jal       func_80124570
/* BA620 80123F20 0000302D */   daddu    $a2, $zero, $zero
/* BA624 80123F24 0804905D */  j         .L80124174
/* BA628 80123F28 00000000 */   nop      
/* BA62C 80123F2C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA630 80123F30 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA634 80123F34 8C420010 */  lw        $v0, 0x10($v0)
/* BA638 80123F38 3042C000 */  andi      $v0, $v0, 0xc000
/* BA63C 80123F3C 10400006 */  beqz      $v0, .L80123F58
/* BA640 80123F40 00000000 */   nop      
/* BA644 80123F44 8E0304FC */  lw        $v1, 0x4fc($s0)
/* BA648 80123F48 30620030 */  andi      $v0, $v1, 0x30
/* BA64C 80123F4C 14400002 */  bnez      $v0, .L80123F58
/* BA650 80123F50 34620100 */   ori      $v0, $v1, 0x100
/* BA654 80123F54 AE0204FC */  sw        $v0, 0x4fc($s0)
.L80123F58:
/* BA658 80123F58 92030464 */  lbu       $v1, 0x464($s0)
/* BA65C 80123F5C 8E020460 */  lw        $v0, 0x460($s0)
/* BA660 80123F60 8E0404FC */  lw        $a0, 0x4fc($s0)
/* BA664 80123F64 00431821 */  addu      $v1, $v0, $v1
/* BA668 80123F68 30820100 */  andi      $v0, $a0, 0x100
/* BA66C 80123F6C 1440000A */  bnez      $v0, .L80123F98
/* BA670 80123F70 AE030460 */   sw       $v1, 0x460($s0)
/* BA674 80123F74 30820014 */  andi      $v0, $a0, 0x14
/* BA678 80123F78 14400009 */  bnez      $v0, .L80123FA0
/* BA67C 80123F7C 00000000 */   nop      
/* BA680 80123F80 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BA684 80123F84 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BA688 80123F88 8C420000 */  lw        $v0, ($v0)
/* BA68C 80123F8C 30428000 */  andi      $v0, $v0, 0x8000
/* BA690 80123F90 10400003 */  beqz      $v0, .L80123FA0
/* BA694 80123F94 00000000 */   nop      
.L80123F98:
/* BA698 80123F98 24620006 */  addiu     $v0, $v1, 6
/* BA69C 80123F9C AE020460 */  sw        $v0, 0x460($s0)
.L80123FA0:
/* BA6A0 80123FA0 96030466 */  lhu       $v1, 0x466($s0)
/* BA6A4 80123FA4 8E020460 */  lw        $v0, 0x460($s0)
/* BA6A8 80123FA8 0043102A */  slt       $v0, $v0, $v1
/* BA6AC 80123FAC 14400071 */  bnez      $v0, .L80124174
/* BA6B0 80123FB0 24020004 */   addiu    $v0, $zero, 4
/* BA6B4 80123FB4 A20204F8 */  sb        $v0, 0x4f8($s0)
/* BA6B8 80123FB8 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BA6BC 80123FBC AE030460 */  sw        $v1, 0x460($s0)
/* BA6C0 80123FC0 92030508 */  lbu       $v1, 0x508($s0)
/* BA6C4 80123FC4 34420004 */  ori       $v0, $v0, 4
/* BA6C8 80123FC8 2463FFF9 */  addiu     $v1, $v1, -7
/* BA6CC 80123FCC 2C630002 */  sltiu     $v1, $v1, 2
/* BA6D0 80123FD0 14600008 */  bnez      $v1, .L80123FF4
/* BA6D4 80123FD4 AE0204FC */   sw       $v0, 0x4fc($s0)
/* BA6D8 80123FD8 9603000C */  lhu       $v1, 0xc($s0)
/* BA6DC 80123FDC 8E020000 */  lw        $v0, ($s0)
/* BA6E0 80123FE0 00431021 */  addu      $v0, $v0, $v1
/* BA6E4 80123FE4 90430000 */  lbu       $v1, ($v0)
/* BA6E8 80123FE8 240200F1 */  addiu     $v0, $zero, 0xf1
/* BA6EC 80123FEC 14620003 */  bne       $v1, $v0, .L80123FFC
/* BA6F0 80123FF0 24020005 */   addiu    $v0, $zero, 5
.L80123FF4:
/* BA6F4 80123FF4 08049000 */  j         .L80124000
/* BA6F8 80123FF8 A600000E */   sh       $zero, 0xe($s0)
.L80123FFC:
/* BA6FC 80123FFC A602000E */  sh        $v0, 0xe($s0)
.L80124000:
/* BA700 80124000 92020486 */  lbu       $v0, 0x486($s0)
/* BA704 80124004 96030462 */  lhu       $v1, 0x462($s0)
/* BA708 80124008 00021040 */  sll       $v0, $v0, 1
/* BA70C 8012400C 02021021 */  addu      $v0, $s0, $v0
/* BA710 80124010 0804905D */  j         .L80124174
/* BA714 80124014 A4430488 */   sh       $v1, 0x488($v0)
/* BA718 80124018 960204CC */  lhu       $v0, 0x4cc($s0)
/* BA71C 8012401C 92030487 */  lbu       $v1, 0x487($s0)
/* BA720 80124020 24420001 */  addiu     $v0, $v0, 1
/* BA724 80124024 00031840 */  sll       $v1, $v1, 1
/* BA728 80124028 02031821 */  addu      $v1, $s0, $v1
/* BA72C 8012402C A60204CC */  sh        $v0, 0x4cc($s0)
/* BA730 80124030 94620488 */  lhu       $v0, 0x488($v1)
/* BA734 80124034 8E030460 */  lw        $v1, 0x460($s0)
/* BA738 80124038 00621823 */  subu      $v1, $v1, $v0
/* BA73C 8012403C 960204C8 */  lhu       $v0, 0x4c8($s0)
/* BA740 80124040 04620001 */  bltzl     $v1, .L80124048
/* BA744 80124044 00031823 */   negu     $v1, $v1
.L80124048:
/* BA748 80124048 2C420011 */  sltiu     $v0, $v0, 0x11
/* BA74C 8012404C 10400008 */  beqz      $v0, .L80124070
/* BA750 80124050 24040002 */   addiu    $a0, $zero, 2
/* BA754 80124054 00031400 */  sll       $v0, $v1, 0x10
/* BA758 80124058 00021C03 */  sra       $v1, $v0, 0x10
/* BA75C 8012405C 2862000F */  slti      $v0, $v1, 0xf
/* BA760 80124060 10400018 */  beqz      $v0, .L801240C4
/* BA764 80124064 28620009 */   slti     $v0, $v1, 9
/* BA768 80124068 08049033 */  j         .L801240CC
/* BA76C 8012406C 00000000 */   nop      
.L80124070:
/* BA770 80124070 00031400 */  sll       $v0, $v1, 0x10
/* BA774 80124074 00021C03 */  sra       $v1, $v0, 0x10
/* BA778 80124078 28620061 */  slti      $v0, $v1, 0x61
/* BA77C 8012407C 14400003 */  bnez      $v0, .L8012408C
/* BA780 80124080 28620031 */   slti     $v0, $v1, 0x31
/* BA784 80124084 08049035 */  j         .L801240D4
/* BA788 80124088 2404000A */   addiu    $a0, $zero, 0xa
.L8012408C:
/* BA78C 8012408C 14400003 */  bnez      $v0, .L8012409C
/* BA790 80124090 28620018 */   slti     $v0, $v1, 0x18
/* BA794 80124094 08049035 */  j         .L801240D4
/* BA798 80124098 24040009 */   addiu    $a0, $zero, 9
.L8012409C:
/* BA79C 8012409C 14400003 */  bnez      $v0, .L801240AC
/* BA7A0 801240A0 28620010 */   slti     $v0, $v1, 0x10
/* BA7A4 801240A4 08049035 */  j         .L801240D4
/* BA7A8 801240A8 24040007 */   addiu    $a0, $zero, 7
.L801240AC:
/* BA7AC 801240AC 14400003 */  bnez      $v0, .L801240BC
/* BA7B0 801240B0 28620008 */   slti     $v0, $v1, 8
/* BA7B4 801240B4 08049035 */  j         .L801240D4
/* BA7B8 801240B8 24040005 */   addiu    $a0, $zero, 5
.L801240BC:
/* BA7BC 801240BC 14400003 */  bnez      $v0, .L801240CC
/* BA7C0 801240C0 28620005 */   slti     $v0, $v1, 5
.L801240C4:
/* BA7C4 801240C4 08049035 */  j         .L801240D4
/* BA7C8 801240C8 24040004 */   addiu    $a0, $zero, 4
.L801240CC:
/* BA7CC 801240CC 50400001 */  beql      $v0, $zero, .L801240D4
/* BA7D0 801240D0 24040003 */   addiu    $a0, $zero, 3
.L801240D4:
/* BA7D4 801240D4 92020487 */  lbu       $v0, 0x487($s0)
/* BA7D8 801240D8 8E030460 */  lw        $v1, 0x460($s0)
/* BA7DC 801240DC A60404CA */  sh        $a0, 0x4ca($s0)
/* BA7E0 801240E0 00021040 */  sll       $v0, $v0, 1
/* BA7E4 801240E4 02021021 */  addu      $v0, $s0, $v0
/* BA7E8 801240E8 94420488 */  lhu       $v0, 0x488($v0)
/* BA7EC 801240EC 0043102A */  slt       $v0, $v0, $v1
/* BA7F0 801240F0 5040000E */  beql      $v0, $zero, .L8012412C
/* BA7F4 801240F4 00831821 */   addu     $v1, $a0, $v1
/* BA7F8 801240F8 92020487 */  lbu       $v0, 0x487($s0)
/* BA7FC 801240FC 00641823 */  subu      $v1, $v1, $a0
/* BA800 80124100 AE030460 */  sw        $v1, 0x460($s0)
/* BA804 80124104 00021040 */  sll       $v0, $v0, 1
/* BA808 80124108 02021021 */  addu      $v0, $s0, $v0
/* BA80C 8012410C 94420488 */  lhu       $v0, 0x488($v0)
/* BA810 80124110 0043182A */  slt       $v1, $v0, $v1
/* BA814 80124114 14600017 */  bnez      $v1, .L80124174
/* BA818 80124118 00000000 */   nop      
/* BA81C 8012411C AE020460 */  sw        $v0, 0x460($s0)
/* BA820 80124120 2402000C */  addiu     $v0, $zero, 0xc
/* BA824 80124124 0804905D */  j         .L80124174
/* BA828 80124128 A20204F8 */   sb       $v0, 0x4f8($s0)
.L8012412C:
/* BA82C 8012412C 92020487 */  lbu       $v0, 0x487($s0)
/* BA830 80124130 AE030460 */  sw        $v1, 0x460($s0)
/* BA834 80124134 00021040 */  sll       $v0, $v0, 1
/* BA838 80124138 02021021 */  addu      $v0, $s0, $v0
/* BA83C 8012413C 94420488 */  lhu       $v0, 0x488($v0)
/* BA840 80124140 0062182A */  slt       $v1, $v1, $v0
/* BA844 80124144 1460000B */  bnez      $v1, .L80124174
/* BA848 80124148 00000000 */   nop      
/* BA84C 8012414C 92040487 */  lbu       $a0, 0x487($s0)
/* BA850 80124150 92030486 */  lbu       $v1, 0x486($s0)
/* BA854 80124154 AE020460 */  sw        $v0, 0x460($s0)
/* BA858 80124158 2402000C */  addiu     $v0, $zero, 0xc
/* BA85C 8012415C 14830005 */  bne       $a0, $v1, .L80124174
/* BA860 80124160 A20204F8 */   sb       $v0, 0x4f8($s0)
/* BA864 80124164 24020005 */  addiu     $v0, $zero, 5
/* BA868 80124168 A20204F8 */  sb        $v0, 0x4f8($s0)
/* BA86C 8012416C A200047C */  sb        $zero, 0x47c($s0)
/* BA870 80124170 A600047E */  sh        $zero, 0x47e($s0)
.L80124174:
/* BA874 80124174 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BA878 80124178 30420001 */  andi      $v0, $v0, 1
/* BA87C 8012417C 1040001B */  beqz      $v0, .L801241EC
/* BA880 80124180 00000000 */   nop      
/* BA884 80124184 8E040544 */  lw        $a0, 0x544($s0)
/* BA888 80124188 A20004F8 */  sb        $zero, 0x4f8($s0)
/* BA88C 8012418C 10800003 */  beqz      $a0, .L8012419C
/* BA890 80124190 AE0004FC */   sw       $zero, 0x4fc($s0)
/* BA894 80124194 0C00AB1E */  jal       general_heap_free
/* BA898 80124198 00000000 */   nop      
.L8012419C:
/* BA89C 8012419C 8E040548 */  lw        $a0, 0x548($s0)
/* BA8A0 801241A0 10800003 */  beqz      $a0, .L801241B0
/* BA8A4 801241A4 00000000 */   nop      
/* BA8A8 801241A8 0C00AB1E */  jal       general_heap_free
/* BA8AC 801241AC 00000000 */   nop      
.L801241B0:
/* BA8B0 801241B0 8E04054C */  lw        $a0, 0x54c($s0)
/* BA8B4 801241B4 10800003 */  beqz      $a0, .L801241C4
/* BA8B8 801241B8 00000000 */   nop      
/* BA8BC 801241BC 0C00AB1E */  jal       general_heap_free
/* BA8C0 801241C0 00000000 */   nop      
.L801241C4:
/* BA8C4 801241C4 8E040550 */  lw        $a0, 0x550($s0)
/* BA8C8 801241C8 10800003 */  beqz      $a0, .L801241D8
/* BA8CC 801241CC 00000000 */   nop      
/* BA8D0 801241D0 0C00AB1E */  jal       general_heap_free
/* BA8D4 801241D4 00000000 */   nop      
.L801241D8:
/* BA8D8 801241D8 8E030504 */  lw        $v1, 0x504($s0)
/* BA8DC 801241DC 10600003 */  beqz      $v1, .L801241EC
/* BA8E0 801241E0 24020001 */   addiu    $v0, $zero, 1
/* BA8E4 801241E4 AC620000 */  sw        $v0, ($v1)
/* BA8E8 801241E8 AE000504 */  sw        $zero, 0x504($s0)
.L801241EC:
/* BA8EC 801241EC 920204F8 */  lbu       $v0, 0x4f8($s0)
/* BA8F0 801241F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA8F4 801241F4 8FB10014 */  lw        $s1, 0x14($sp)
/* BA8F8 801241F8 8FB00010 */  lw        $s0, 0x10($sp)
/* BA8FC 801241FC 03E00008 */  jr        $ra
/* BA900 80124200 27BD0020 */   addiu    $sp, $sp, 0x20
