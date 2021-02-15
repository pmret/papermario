.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C4_EB1224
/* EB1224 802403C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB1228 802403C8 AFB00010 */  sw        $s0, 0x10($sp)
/* EB122C 802403CC 0080802D */  daddu     $s0, $a0, $zero
/* EB1230 802403D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB1234 802403D4 AFB10014 */  sw        $s1, 0x14($sp)
/* EB1238 802403D8 8E02000C */  lw        $v0, 0xc($s0)
/* EB123C 802403DC 8C510000 */  lw        $s1, ($v0)
/* EB1240 802403E0 0C0B53A3 */  jal       func_802D4E8C
/* EB1244 802403E4 0220282D */   daddu    $a1, $s1, $zero
/* EB1248 802403E8 3C03FFF0 */  lui       $v1, 0xfff0
/* EB124C 802403EC 3463FFFF */  ori       $v1, $v1, 0xffff
/* EB1250 802403F0 0200202D */  daddu     $a0, $s0, $zero
/* EB1254 802403F4 00431024 */  and       $v0, $v0, $v1
/* EB1258 802403F8 00021140 */  sll       $v0, $v0, 5
/* EB125C 802403FC 3C068009 */  lui       $a2, %hi(D_8008D2C0)
/* EB1260 80240400 00C23021 */  addu      $a2, $a2, $v0
/* EB1264 80240404 8CC6D2C0 */  lw        $a2, %lo(D_8008D2C0)($a2)
/* EB1268 80240408 0C0B551A */  jal       func_802D5468
/* EB126C 8024040C 0220282D */   daddu    $a1, $s1, $zero
/* EB1270 80240410 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB1274 80240414 8FB10014 */  lw        $s1, 0x14($sp)
/* EB1278 80240418 8FB00010 */  lw        $s0, 0x10($sp)
/* EB127C 8024041C 24020002 */  addiu     $v0, $zero, 2
/* EB1280 80240420 03E00008 */  jr        $ra
/* EB1284 80240424 27BD0020 */   addiu    $sp, $sp, 0x20
