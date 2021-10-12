.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_97_update
/* 3C12FC E00C212C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3C1300 E00C2130 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3C1304 E00C2134 8C830000 */  lw        $v1, ($a0)
/* 3C1308 E00C2138 8C85000C */  lw        $a1, 0xc($a0)
/* 3C130C E00C213C 30620010 */  andi      $v0, $v1, 0x10
/* 3C1310 E00C2140 10400005 */  beqz      $v0, .LE00C2158
/* 3C1314 E00C2144 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3C1318 E00C2148 00621024 */  and       $v0, $v1, $v0
/* 3C131C E00C214C AC820000 */  sw        $v0, ($a0)
/* 3C1320 E00C2150 24020010 */  addiu     $v0, $zero, 0x10
/* 3C1324 E00C2154 ACA20010 */  sw        $v0, 0x10($a1)
.LE00C2158:
/* 3C1328 E00C2158 8CA30010 */  lw        $v1, 0x10($a1)
/* 3C132C E00C215C 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3C1330 E00C2160 10400002 */  beqz      $v0, .LE00C216C
/* 3C1334 E00C2164 2462FFFF */   addiu    $v0, $v1, -1
/* 3C1338 E00C2168 ACA20010 */  sw        $v0, 0x10($a1)
.LE00C216C:
/* 3C133C E00C216C 8CA20014 */  lw        $v0, 0x14($a1)
/* 3C1340 E00C2170 8CA60010 */  lw        $a2, 0x10($a1)
/* 3C1344 E00C2174 24430001 */  addiu     $v1, $v0, 1
/* 3C1348 E00C2178 04C10005 */  bgez      $a2, .LE00C2190
/* 3C134C E00C217C ACA30014 */   sw       $v1, 0x14($a1)
/* 3C1350 E00C2180 0C080128 */  jal       shim_remove_effect
/* 3C1354 E00C2184 00000000 */   nop
/* 3C1358 E00C2188 08030870 */  j         .LE00C21C0
/* 3C135C E00C218C 00000000 */   nop
.LE00C2190:
/* 3C1360 E00C2190 28620010 */  slti      $v0, $v1, 0x10
/* 3C1364 E00C2194 10400004 */  beqz      $v0, .LE00C21A8
/* 3C1368 E00C2198 00C0202D */   daddu    $a0, $a2, $zero
/* 3C136C E00C219C 00031100 */  sll       $v0, $v1, 4
/* 3C1370 E00C21A0 0803086B */  j         .LE00C21AC
/* 3C1374 E00C21A4 2442000F */   addiu    $v0, $v0, 0xf
.LE00C21A8:
/* 3C1378 E00C21A8 240200FF */  addiu     $v0, $zero, 0xff
.LE00C21AC:
/* 3C137C E00C21AC ACA20024 */  sw        $v0, 0x24($a1)
/* 3C1380 E00C21B0 28820010 */  slti      $v0, $a0, 0x10
/* 3C1384 E00C21B4 10400002 */  beqz      $v0, .LE00C21C0
/* 3C1388 E00C21B8 00041100 */   sll      $v0, $a0, 4
/* 3C138C E00C21BC ACA20024 */  sw        $v0, 0x24($a1)
.LE00C21C0:
/* 3C1390 E00C21C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3C1394 E00C21C4 03E00008 */  jr        $ra
/* 3C1398 E00C21C8 27BD0018 */   addiu    $sp, $sp, 0x18
