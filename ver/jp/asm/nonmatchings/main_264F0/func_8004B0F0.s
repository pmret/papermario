.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B0F0
/* 264F0 8004B0F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 264F4 8004B0F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 264F8 8004B0F8 0080802D */  daddu     $s0, $a0, $zero
/* 264FC 8004B0FC 3C030006 */  lui       $v1, 6
/* 26500 8004B100 3463A25E */  ori       $v1, $v1, 0xa25e
/* 26504 8004B104 3C020004 */  lui       $v0, 4
/* 26508 8004B108 8FA40028 */  lw        $a0, 0x28($sp)
/* 2650C 8004B10C 3442C4B4 */  ori       $v0, $v0, 0xc4b4
/* 26510 8004B110 AFBF0014 */  sw        $ra, 0x14($sp)
/* 26514 8004B114 AE070000 */  sw        $a3, ($s0)
/* 26518 8004B118 AE020034 */  sw        $v0, 0x34($s0)
/* 2651C 8004B11C AE03003C */  sw        $v1, 0x3c($s0)
/* 26520 8004B120 AE030038 */  sw        $v1, 0x38($s0)
/* 26524 8004B124 A20500BC */  sb        $a1, 0xbc($s0)
/* 26528 8004B128 308200FF */  andi      $v0, $a0, 0xff
/* 2652C 8004B12C 2C420011 */  sltiu     $v0, $v0, 0x11
/* 26530 8004B130 14400004 */  bnez      $v0, .L8004B144
/* 26534 8004B134 A20600BE */   sb       $a2, 0xbe($s0)
/* 26538 8004B138 24020010 */  addiu     $v0, $zero, 0x10
/* 2653C 8004B13C 08012C52 */  j         .L8004B148
/* 26540 8004B140 A20200BD */   sb       $v0, 0xbd($s0)
.L8004B144:
/* 26544 8004B144 A20400BD */  sb        $a0, 0xbd($s0)
.L8004B148:
/* 26548 8004B148 0000202D */  daddu     $a0, $zero, $zero
/* 2654C 8004B14C 24060040 */  addiu     $a2, $zero, 0x40
/* 26550 8004B150 240500B0 */  addiu     $a1, $zero, 0xb0
/* 26554 8004B154 2403016C */  addiu     $v1, $zero, 0x16c
/* 26558 8004B158 34028000 */  ori       $v0, $zero, 0x8000
/* 2655C 8004B15C AE02005C */  sw        $v0, 0x5c($s0)
/* 26560 8004B160 A60200B8 */  sh        $v0, 0xb8($s0)
/* 26564 8004B164 AE000030 */  sw        $zero, 0x30($s0)
/* 26568 8004B168 AE000060 */  sw        $zero, 0x60($s0)
.L8004B16C:
/* 2656C 8004B16C 02031021 */  addu      $v0, $s0, $v1
/* 26570 8004B170 24840001 */  addiu     $a0, $a0, 1
/* 26574 8004B174 AC400000 */  sw        $zero, ($v0)
/* 26578 8004B178 A440005C */  sh        $zero, 0x5c($v0)
/* 2657C 8004B17C A440008E */  sh        $zero, 0x8e($v0)
/* 26580 8004B180 A4400090 */  sh        $zero, 0x90($v0)
/* 26584 8004B184 A4400092 */  sh        $zero, 0x92($v0)
/* 26588 8004B188 A0400094 */  sb        $zero, 0x94($v0)
/* 2658C 8004B18C A040009B */  sb        $zero, 0x9b($v0)
/* 26590 8004B190 A040009C */  sb        $zero, 0x9c($v0)
/* 26594 8004B194 A040009D */  sb        $zero, 0x9d($v0)
/* 26598 8004B198 A040009E */  sb        $zero, 0x9e($v0)
/* 2659C 8004B19C A040009F */  sb        $zero, 0x9f($v0)
/* 265A0 8004B1A0 A0400099 */  sb        $zero, 0x99($v0)
/* 265A4 8004B1A4 A0400078 */  sb        $zero, 0x78($v0)
/* 265A8 8004B1A8 A0400079 */  sb        $zero, 0x79($v0)
/* 265AC 8004B1AC A040007A */  sb        $zero, 0x7a($v0)
/* 265B0 8004B1B0 A046007B */  sb        $a2, 0x7b($v0)
/* 265B4 8004B1B4 A040007C */  sb        $zero, 0x7c($v0)
/* 265B8 8004B1B8 A045007D */  sb        $a1, 0x7d($v0)
/* 265BC 8004B1BC A040007E */  sb        $zero, 0x7e($v0)
/* 265C0 8004B1C0 A040007F */  sb        $zero, 0x7f($v0)
/* 265C4 8004B1C4 2C820008 */  sltiu     $v0, $a0, 8
/* 265C8 8004B1C8 1440FFE8 */  bnez      $v0, .L8004B16C
/* 265CC 8004B1CC 246300AC */   addiu    $v1, $v1, 0xac
/* 265D0 8004B1D0 0000202D */  daddu     $a0, $zero, $zero
/* 265D4 8004B1D4 0200182D */  daddu     $v1, $s0, $zero
.L8004B1D8:
/* 265D8 8004B1D8 AC600090 */  sw        $zero, 0x90($v1)
/* 265DC 8004B1DC 24840001 */  addiu     $a0, $a0, 1
/* 265E0 8004B1E0 2C820004 */  sltiu     $v0, $a0, 4
/* 265E4 8004B1E4 1440FFFC */  bnez      $v0, .L8004B1D8
/* 265E8 8004B1E8 24630004 */   addiu    $v1, $v1, 4
/* 265EC 8004B1EC 0000202D */  daddu     $a0, $zero, $zero
/* 265F0 8004B1F0 0200182D */  daddu     $v1, $s0, $zero
.L8004B1F4:
/* 265F4 8004B1F4 A46000A0 */  sh        $zero, 0xa0($v1)
/* 265F8 8004B1F8 24840001 */  addiu     $a0, $a0, 1
/* 265FC 8004B1FC 2C820004 */  sltiu     $v0, $a0, 4
/* 26600 8004B200 1440FFFC */  bnez      $v0, .L8004B1F4
/* 26604 8004B204 24630006 */   addiu    $v1, $v1, 6
/* 26608 8004B208 0200202D */  daddu     $a0, $s0, $zero
/* 2660C 8004B20C 0000282D */  daddu     $a1, $zero, $zero
/* 26610 8004B210 0C012DC1 */  jal       func_8004B704
/* 26614 8004B214 AE000168 */   sw       $zero, 0x168($s0)
/* 26618 8004B218 0C012CD2 */  jal       func_8004B348
/* 2661C 8004B21C 0200202D */   daddu    $a0, $s0, $zero
/* 26620 8004B220 26040040 */  addiu     $a0, $s0, 0x40
/* 26624 8004B224 0000282D */  daddu     $a1, $zero, $zero
/* 26628 8004B228 24067FFF */  addiu     $a2, $zero, 0x7fff
/* 2662C 8004B22C 0C014D89 */  jal       func_80053624
/* 26630 8004B230 00C0382D */   daddu    $a3, $a2, $zero
/* 26634 8004B234 920400BE */  lbu       $a0, 0xbe($s0)
/* 26638 8004B238 96050040 */  lhu       $a1, 0x40($s0)
/* 2663C 8004B23C 0C014DD2 */  jal       func_80053748
/* 26640 8004B240 8E06005C */   lw       $a2, 0x5c($s0)
/* 26644 8004B244 0200202D */  daddu     $a0, $s0, $zero
/* 26648 8004B248 0000282D */  daddu     $a1, $zero, $zero
/* 2664C 8004B24C 240200FF */  addiu     $v0, $zero, 0xff
/* 26650 8004B250 A082008C */  sb        $v0, 0x8c($a0)
/* 26654 8004B254 3C028008 */  lui       $v0, %hi(D_80078260)
/* 26658 8004B258 24428260 */  addiu     $v0, $v0, %lo(D_80078260)
/* 2665C 8004B25C AC820064 */  sw        $v0, 0x64($a0)
/* 26660 8004B260 3C028008 */  lui       $v0, %hi(D_800782C8)
/* 26664 8004B264 244282C8 */  addiu     $v0, $v0, %lo(D_800782C8)
/* 26668 8004B268 AC820068 */  sw        $v0, 0x68($a0)
/* 2666C 8004B26C 3C028008 */  lui       $v0, %hi(D_800782F0)
/* 26670 8004B270 244282F0 */  addiu     $v0, $v0, %lo(D_800782F0)
/* 26674 8004B274 AC82006C */  sw        $v0, 0x6c($a0)
/* 26678 8004B278 3C028008 */  lui       $v0, %hi(D_80078318)
/* 2667C 8004B27C 24428318 */  addiu     $v0, $v0, %lo(D_80078318)
/* 26680 8004B280 AC820070 */  sw        $v0, 0x70($a0)
/* 26684 8004B284 AC820074 */  sw        $v0, 0x74($a0)
/* 26688 8004B288 AC820078 */  sw        $v0, 0x78($a0)
/* 2668C 8004B28C AC82007C */  sw        $v0, 0x7c($a0)
/* 26690 8004B290 AC820080 */  sw        $v0, 0x80($a0)
/* 26694 8004B294 24020010 */  addiu     $v0, $zero, 0x10
/* 26698 8004B298 A0820084 */  sb        $v0, 0x84($a0)
/* 2669C 8004B29C 24020020 */  addiu     $v0, $zero, 0x20
/* 266A0 8004B2A0 A0820085 */  sb        $v0, 0x85($a0)
/* 266A4 8004B2A4 A0820086 */  sb        $v0, 0x86($a0)
/* 266A8 8004B2A8 A0820087 */  sb        $v0, 0x87($a0)
/* 266AC 8004B2AC A0820088 */  sb        $v0, 0x88($a0)
/* 266B0 8004B2B0 24020030 */  addiu     $v0, $zero, 0x30
/* 266B4 8004B2B4 A0820089 */  sb        $v0, 0x89($a0)
/* 266B8 8004B2B8 24020040 */  addiu     $v0, $zero, 0x40
/* 266BC 8004B2BC A082008A */  sb        $v0, 0x8a($a0)
/* 266C0 8004B2C0 24020050 */  addiu     $v0, $zero, 0x50
/* 266C4 8004B2C4 0C012DA5 */  jal       func_8004B694
/* 266C8 8004B2C8 A082008B */   sb       $v0, 0x8b($a0)
/* 266CC 8004B2CC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 266D0 8004B2D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 266D4 8004B2D4 03E00008 */  jr        $ra
/* 266D8 8004B2D8 27BD0018 */   addiu    $sp, $sp, 0x18
