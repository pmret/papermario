.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240374_D7F0D4
/* D7F0D4 80240374 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7F0D8 80240378 AFBF0010 */  sw        $ra, 0x10($sp)
/* D7F0DC 8024037C 8C82000C */  lw        $v0, 0xc($a0)
/* D7F0E0 80240380 0C0B1EAF */  jal       get_variable
/* D7F0E4 80240384 8C450000 */   lw       $a1, ($v0)
/* D7F0E8 80240388 0040182D */  daddu     $v1, $v0, $zero
/* D7F0EC 8024038C 10600012 */  beqz      $v1, .L802403D8
/* D7F0F0 80240390 0000202D */   daddu    $a0, $zero, $zero
/* D7F0F4 80240394 8C620000 */  lw        $v0, ($v1)
/* D7F0F8 80240398 5040000A */  beql      $v0, $zero, .L802403C4
/* D7F0FC 8024039C 00041080 */   sll      $v0, $a0, 2
/* D7F100 802403A0 3C058024 */  lui       $a1, %hi(D_80247E68)
/* D7F104 802403A4 24A57E68 */  addiu     $a1, $a1, %lo(D_80247E68)
.L802403A8:
/* D7F108 802403A8 24630004 */  addiu     $v1, $v1, 4
/* D7F10C 802403AC 24840001 */  addiu     $a0, $a0, 1
/* D7F110 802403B0 ACA20000 */  sw        $v0, ($a1)
/* D7F114 802403B4 8C620000 */  lw        $v0, ($v1)
/* D7F118 802403B8 1440FFFB */  bnez      $v0, .L802403A8
/* D7F11C 802403BC 24A50004 */   addiu    $a1, $a1, 4
/* D7F120 802403C0 00041080 */  sll       $v0, $a0, 2
.L802403C4:
/* D7F124 802403C4 3C018024 */  lui       $at, %hi(D_80247E68)
/* D7F128 802403C8 00220821 */  addu      $at, $at, $v0
/* D7F12C 802403CC AC207E68 */  sw        $zero, %lo(D_80247E68)($at)
/* D7F130 802403D0 08090100 */  j         .L80240400
/* D7F134 802403D4 00000000 */   nop      
.L802403D8:
/* D7F138 802403D8 3C038024 */  lui       $v1, %hi(D_80247E68)
/* D7F13C 802403DC 24637E68 */  addiu     $v1, $v1, %lo(D_80247E68)
/* D7F140 802403E0 0060282D */  daddu     $a1, $v1, $zero
.L802403E4:
/* D7F144 802403E4 24820080 */  addiu     $v0, $a0, 0x80
/* D7F148 802403E8 AC620000 */  sw        $v0, ($v1)
/* D7F14C 802403EC 24630004 */  addiu     $v1, $v1, 4
/* D7F150 802403F0 24840001 */  addiu     $a0, $a0, 1
/* D7F154 802403F4 2882005B */  slti      $v0, $a0, 0x5b
/* D7F158 802403F8 1440FFFA */  bnez      $v0, .L802403E4
/* D7F15C 802403FC ACA0016C */   sw       $zero, 0x16c($a1)
.L80240400:
/* D7F160 80240400 8FBF0010 */  lw        $ra, 0x10($sp)
/* D7F164 80240404 24020002 */  addiu     $v0, $zero, 2
/* D7F168 80240408 03E00008 */  jr        $ra
/* D7F16C 8024040C 27BD0018 */   addiu    $sp, $sp, 0x18
