.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80098290
.word L800341F8_F5F8, L8003411C_F51C, L80034150_F550, L80034170_F570, L800341A8_F5A8, L800341D8_F5D8, L800341F8_F5F8, L80034230_F630, L80034278_F678, L800342D4_F6D4, L800342FC_F6FC, L8003432C_F72C

.section .text

glabel step_logos
/* F4A4 800340A4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* F4A8 800340A8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* F4AC 800340AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F4B0 800340B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* F4B4 800340B4 AFB00010 */  sw        $s0, 0x10($sp)
/* F4B8 800340B8 806200AE */  lb        $v0, 0xae($v1)
/* F4BC 800340BC 1040000E */  beqz      $v0, .L800340F8
/* F4C0 800340C0 00000000 */   nop
/* F4C4 800340C4 0C00CE0C */  jal       intro_logos_fade_out
/* F4C8 800340C8 2404000A */   addiu    $a0, $zero, 0xa
/* F4CC 800340CC 104000A4 */  beqz      $v0, .L80034360
/* F4D0 800340D0 00000000 */   nop
/* F4D4 800340D4 3C013F80 */  lui       $at, 0x3f80
/* F4D8 800340D8 44816000 */  mtc1      $at, $f12
/* F4DC 800340DC 0C00AFBB */  jal       set_curtain_scale
/* F4E0 800340E0 00000000 */   nop
/* F4E4 800340E4 44806000 */  mtc1      $zero, $f12
/* F4E8 800340E8 0C00AFC9 */  jal       set_curtain_fade
/* F4EC 800340EC 00000000 */   nop
/* F4F0 800340F0 0800D0D6 */  j         .L80034358
/* F4F4 800340F4 24040002 */   addiu    $a0, $zero, 2
.L800340F8:
/* F4F8 800340F8 806300AC */  lb        $v1, 0xac($v1)
/* F4FC 800340FC 2C62000C */  sltiu     $v0, $v1, 0xc
/* F500 80034100 10400097 */  beqz      $v0, .L80034360
/* F504 80034104 00031080 */   sll      $v0, $v1, 2
/* F508 80034108 3C01800A */  lui       $at, %hi(jtbl_80098290)
/* F50C 8003410C 00220821 */  addu      $at, $at, $v0
/* F510 80034110 8C228290 */  lw        $v0, %lo(jtbl_80098290)($at)
/* F514 80034114 00400008 */  jr        $v0
/* F518 80034118 00000000 */   nop
glabel L8003411C_F51C
/* F51C 8003411C 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* F520 80034120 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* F524 80034124 8E020000 */  lw        $v0, ($s0)
/* F528 80034128 804200AD */  lb        $v0, 0xad($v0)
/* F52C 8003412C 1440004D */  bnez      $v0, .L80034264
/* F530 80034130 00000000 */   nop
/* F534 80034134 0C00CDF8 */  jal       intro_logos_set_fade_color
/* F538 80034138 240400D0 */   addiu    $a0, $zero, 0xd0
/* F53C 8003413C 8E030000 */  lw        $v1, ($s0)
/* F540 80034140 906200AC */  lbu       $v0, 0xac($v1)
/* F544 80034144 24420001 */  addiu     $v0, $v0, 1
/* F548 80034148 0800D099 */  j         .L80034264
/* F54C 8003414C A06200AC */   sb       $v0, 0xac($v1)
glabel L80034150_F550
/* F550 80034150 0C00CE0C */  jal       intro_logos_fade_out
/* F554 80034154 2404000A */   addiu    $a0, $zero, 0xa
/* F558 80034158 10400081 */  beqz      $v0, .L80034360
/* F55C 8003415C 00000000 */   nop
/* F560 80034160 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* F564 80034164 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* F568 80034168 0800D0C5 */  j         .L80034314
/* F56C 8003416C 00000000 */   nop
glabel L80034170_F570
/* F570 80034170 0C00CDFE */  jal       intro_logos_fade_in
/* F574 80034174 2404000A */   addiu    $a0, $zero, 0xa
/* F578 80034178 10400079 */  beqz      $v0, .L80034360
/* F57C 8003417C 00000000 */   nop
/* F580 80034180 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* F584 80034184 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* F588 80034188 8C830000 */  lw        $v1, ($a0)
/* F58C 8003418C 906200AC */  lbu       $v0, 0xac($v1)
/* F590 80034190 24420001 */  addiu     $v0, $v0, 1
/* F594 80034194 A06200AC */  sb        $v0, 0xac($v1)
/* F598 80034198 8C830000 */  lw        $v1, ($a0)
/* F59C 8003419C 24020028 */  addiu     $v0, $zero, 0x28
/* F5A0 800341A0 0800D0D8 */  j         .L80034360
/* F5A4 800341A4 A06200AD */   sb       $v0, 0xad($v1)
glabel L800341A8_F5A8
/* F5A8 800341A8 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* F5AC 800341AC 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* F5B0 800341B0 8E030000 */  lw        $v1, ($s0)
/* F5B4 800341B4 806200AD */  lb        $v0, 0xad($v1)
/* F5B8 800341B8 1440002B */  bnez      $v0, .L80034268
/* F5BC 800341BC 240400D0 */   addiu    $a0, $zero, 0xd0
/* F5C0 800341C0 906200AC */  lbu       $v0, 0xac($v1)
/* F5C4 800341C4 24420001 */  addiu     $v0, $v0, 1
/* F5C8 800341C8 0C00CDF8 */  jal       intro_logos_set_fade_color
/* F5CC 800341CC A06200AC */   sb       $v0, 0xac($v1)
/* F5D0 800341D0 0800D099 */  j         .L80034264
/* F5D4 800341D4 00000000 */   nop
glabel L800341D8_F5D8
/* F5D8 800341D8 0C00CE0C */  jal       intro_logos_fade_out
/* F5DC 800341DC 2404000A */   addiu    $a0, $zero, 0xa
/* F5E0 800341E0 1040005F */  beqz      $v0, .L80034360
/* F5E4 800341E4 00000000 */   nop
/* F5E8 800341E8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* F5EC 800341EC 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* F5F0 800341F0 0800D0C5 */  j         .L80034314
/* F5F4 800341F4 00000000 */   nop
glabel L800341F8_F5F8
/* F5F8 800341F8 0C00CDFE */  jal       intro_logos_fade_in
/* F5FC 800341FC 2404000A */   addiu    $a0, $zero, 0xa
/* F600 80034200 10400057 */  beqz      $v0, .L80034360
/* F604 80034204 00000000 */   nop
/* F608 80034208 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* F60C 8003420C 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* F610 80034210 8C830000 */  lw        $v1, ($a0)
/* F614 80034214 906200AC */  lbu       $v0, 0xac($v1)
/* F618 80034218 24420001 */  addiu     $v0, $v0, 1
/* F61C 8003421C A06200AC */  sb        $v0, 0xac($v1)
/* F620 80034220 8C830000 */  lw        $v1, ($a0)
/* F624 80034224 2402001E */  addiu     $v0, $zero, 0x1e
/* F628 80034228 0800D0D8 */  j         .L80034360
/* F62C 8003422C A06200AD */   sb       $v0, 0xad($v1)
glabel L80034230_F630
/* F630 80034230 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* F634 80034234 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* F638 80034238 8E030000 */  lw        $v1, ($s0)
/* F63C 8003423C 806200AD */  lb        $v0, 0xad($v1)
/* F640 80034240 14400009 */  bnez      $v0, .L80034268
/* F644 80034244 240400D0 */   addiu    $a0, $zero, 0xd0
/* F648 80034248 906200AC */  lbu       $v0, 0xac($v1)
/* F64C 8003424C 24420001 */  addiu     $v0, $v0, 1
/* F650 80034250 0C00CDF8 */  jal       intro_logos_set_fade_color
/* F654 80034254 A06200AC */   sb       $v0, 0xac($v1)
/* F658 80034258 8E030000 */  lw        $v1, ($s0)
/* F65C 8003425C 2402001E */  addiu     $v0, $zero, 0x1e
/* F660 80034260 A06200AD */  sb        $v0, 0xad($v1)
.L80034264:
/* F664 80034264 8E030000 */  lw        $v1, ($s0)
.L80034268:
/* F668 80034268 906200AD */  lbu       $v0, 0xad($v1)
/* F66C 8003426C 2442FFFF */  addiu     $v0, $v0, -1
/* F670 80034270 0800D0D8 */  j         .L80034360
/* F674 80034274 A06200AD */   sb       $v0, 0xad($v1)
glabel L80034278_F678
/* F678 80034278 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* F67C 8003427C 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* F680 80034280 808200AD */  lb        $v0, 0xad($a0)
/* F684 80034284 908300AD */  lbu       $v1, 0xad($a0)
/* F688 80034288 14400010 */  bnez      $v0, .L800342CC
/* F68C 8003428C 2462FFFF */   addiu    $v0, $v1, -1
/* F690 80034290 908200AC */  lbu       $v0, 0xac($a0)
/* F694 80034294 3C013F80 */  lui       $at, 0x3f80
/* F698 80034298 44816000 */  mtc1      $at, $f12
/* F69C 8003429C 24420001 */  addiu     $v0, $v0, 1
/* F6A0 800342A0 0C00AFB7 */  jal       set_curtain_scale_goal
/* F6A4 800342A4 A08200AC */   sb       $v0, 0xac($a0)
/* F6A8 800342A8 0C00AFC1 */  jal       set_curtain_draw_callback
/* F6AC 800342AC 0000202D */   daddu    $a0, $zero, $zero
/* F6B0 800342B0 3C013E99 */  lui       $at, 0x3e99
/* F6B4 800342B4 3421999A */  ori       $at, $at, 0x999a
/* F6B8 800342B8 44816000 */  mtc1      $at, $f12
/* F6BC 800342BC 0C00AFC5 */  jal       set_curtain_fade_goal
/* F6C0 800342C0 00000000 */   nop
/* F6C4 800342C4 0800D0D8 */  j         .L80034360
/* F6C8 800342C8 00000000 */   nop
.L800342CC:
/* F6CC 800342CC 0800D0D8 */  j         .L80034360
/* F6D0 800342D0 A08200AD */   sb       $v0, 0xad($a0)
glabel L800342D4_F6D4
/* F6D4 800342D4 0C00CE0C */  jal       intro_logos_fade_out
/* F6D8 800342D8 2404000A */   addiu    $a0, $zero, 0xa
/* F6DC 800342DC 10400020 */  beqz      $v0, .L80034360
/* F6E0 800342E0 2402000F */   addiu    $v0, $zero, 0xf
/* F6E4 800342E4 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* F6E8 800342E8 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* F6EC 800342EC 8C830000 */  lw        $v1, ($a0)
/* F6F0 800342F0 A06200AD */  sb        $v0, 0xad($v1)
/* F6F4 800342F4 0800D0C5 */  j         .L80034314
/* F6F8 800342F8 8C830000 */   lw       $v1, ($a0)
glabel L800342FC_F6FC
/* F6FC 800342FC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* F700 80034300 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* F704 80034304 806200AD */  lb        $v0, 0xad($v1)
/* F708 80034308 906400AD */  lbu       $a0, 0xad($v1)
/* F70C 8003430C 14400005 */  bnez      $v0, .L80034324
/* F710 80034310 2482FFFF */   addiu    $v0, $a0, -1
.L80034314:
/* F714 80034314 906200AC */  lbu       $v0, 0xac($v1)
/* F718 80034318 24420001 */  addiu     $v0, $v0, 1
/* F71C 8003431C 0800D0D8 */  j         .L80034360
/* F720 80034320 A06200AC */   sb       $v0, 0xac($v1)
.L80034324:
/* F724 80034324 0800D0D8 */  j         .L80034360
/* F728 80034328 A06200AD */   sb       $v0, 0xad($v1)
glabel L8003432C_F72C
/* F72C 8003432C 3C10800A */  lui       $s0, %hi(D_800A0910)
/* F730 80034330 26100910 */  addiu     $s0, $s0, %lo(D_800A0910)
/* F734 80034334 0C00AB4B */  jal       heap_free
/* F738 80034338 8E040000 */   lw       $a0, ($s0)
/* F73C 8003433C 240400FF */  addiu     $a0, $zero, 0xff
/* F740 80034340 0C00CDF4 */  jal       intro_logos_set_fade_alpha
/* F744 80034344 AE000000 */   sw       $zero, ($s0)
/* F748 80034348 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* F74C 8003434C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* F750 80034350 24040010 */  addiu     $a0, $zero, 0x10
/* F754 80034354 A04000A8 */  sb        $zero, 0xa8($v0)
.L80034358:
/* F758 80034358 0C00CD3C */  jal       set_game_mode
/* F75C 8003435C 00000000 */   nop
.L80034360:
/* F760 80034360 0C00E64C */  jal       update_npcs
/* F764 80034364 00000000 */   nop
/* F768 80034368 0C00B500 */  jal       update_cameras
/* F76C 8003436C 00000000 */   nop
/* F770 80034370 0C00CE1D */  jal       intro_logos_update_fade
/* F774 80034374 00000000 */   nop
/* F778 80034378 8FBF0014 */  lw        $ra, 0x14($sp)
/* F77C 8003437C 8FB00010 */  lw        $s0, 0x10($sp)
/* F780 80034380 03E00008 */  jr        $ra
/* F784 80034384 27BD0018 */   addiu    $sp, $sp, 0x18
