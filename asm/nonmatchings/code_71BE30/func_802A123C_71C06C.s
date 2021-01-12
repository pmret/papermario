.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_71C06C
/* 71C06C 802A123C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 71C070 802A1240 AFB1001C */  sw        $s1, 0x1c($sp)
/* 71C074 802A1244 0080882D */  daddu     $s1, $a0, $zero
/* 71C078 802A1248 AFBF0024 */  sw        $ra, 0x24($sp)
/* 71C07C 802A124C AFB20020 */  sw        $s2, 0x20($sp)
/* 71C080 802A1250 AFB00018 */  sw        $s0, 0x18($sp)
/* 71C084 802A1254 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 71C088 802A1258 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 71C08C 802A125C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 71C090 802A1260 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 71C094 802A1264 8E30000C */  lw        $s0, 0xc($s1)
/* 71C098 802A1268 8E050000 */  lw        $a1, ($s0)
/* 71C09C 802A126C 0C0B1EAF */  jal       get_variable
/* 71C0A0 802A1270 26100004 */   addiu    $s0, $s0, 4
/* 71C0A4 802A1274 8E050000 */  lw        $a1, ($s0)
/* 71C0A8 802A1278 26100004 */  addiu     $s0, $s0, 4
/* 71C0AC 802A127C 0220202D */  daddu     $a0, $s1, $zero
/* 71C0B0 802A1280 0C0B1EAF */  jal       get_variable
/* 71C0B4 802A1284 0040902D */   daddu    $s2, $v0, $zero
/* 71C0B8 802A1288 0220202D */  daddu     $a0, $s1, $zero
/* 71C0BC 802A128C 8E050000 */  lw        $a1, ($s0)
/* 71C0C0 802A1290 0C0B1EAF */  jal       get_variable
/* 71C0C4 802A1294 0040802D */   daddu    $s0, $v0, $zero
/* 71C0C8 802A1298 4492D000 */  mtc1      $s2, $f26
/* 71C0CC 802A129C 00000000 */  nop       
/* 71C0D0 802A12A0 4680D6A0 */  cvt.s.w   $f26, $f26
/* 71C0D4 802A12A4 4490C000 */  mtc1      $s0, $f24
/* 71C0D8 802A12A8 00000000 */  nop       
/* 71C0DC 802A12AC 4680C620 */  cvt.s.w   $f24, $f24
/* 71C0E0 802A12B0 4482A000 */  mtc1      $v0, $f20
/* 71C0E4 802A12B4 00000000 */  nop       
/* 71C0E8 802A12B8 4680A520 */  cvt.s.w   $f20, $f20
/* 71C0EC 802A12BC 4405D000 */  mfc1      $a1, $f26
/* 71C0F0 802A12C0 4406C000 */  mfc1      $a2, $f24
/* 71C0F4 802A12C4 4407A000 */  mfc1      $a3, $f20
/* 71C0F8 802A12C8 3C0141F0 */  lui       $at, 0x41f0
/* 71C0FC 802A12CC 4481B000 */  mtc1      $at, $f22
/* 71C100 802A12D0 24040002 */  addiu     $a0, $zero, 2
/* 71C104 802A12D4 0C01BFBC */  jal       func_8006FEF0
/* 71C108 802A12D8 E7B60010 */   swc1     $f22, 0x10($sp)
/* 71C10C 802A12DC 4405D000 */  mfc1      $a1, $f26
/* 71C110 802A12E0 4406C000 */  mfc1      $a2, $f24
/* 71C114 802A12E4 4407A000 */  mfc1      $a3, $f20
/* 71C118 802A12E8 24040002 */  addiu     $a0, $zero, 2
/* 71C11C 802A12EC 0C01BFBC */  jal       func_8006FEF0
/* 71C120 802A12F0 E7B60010 */   swc1     $f22, 0x10($sp)
/* 71C124 802A12F4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 71C128 802A12F8 8FB20020 */  lw        $s2, 0x20($sp)
/* 71C12C 802A12FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 71C130 802A1300 8FB00018 */  lw        $s0, 0x18($sp)
/* 71C134 802A1304 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 71C138 802A1308 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 71C13C 802A130C D7B60030 */  ldc1      $f22, 0x30($sp)
/* 71C140 802A1310 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 71C144 802A1314 24020002 */  addiu     $v0, $zero, 2
/* 71C148 802A1318 03E00008 */  jr        $ra
/* 71C14C 802A131C 27BD0048 */   addiu    $sp, $sp, 0x48
