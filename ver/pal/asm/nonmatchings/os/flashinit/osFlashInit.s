.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel osFlashInit
/* 3D0B0 80061CB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3D0B4 80061CB4 3C04800D */  lui       $a0, %hi(D_800D59B0)
/* 3D0B8 80061CB8 248459B0 */  addiu     $a0, $a0, %lo(D_800D59B0)
/* 3D0BC 80061CBC 3C058009 */  lui       $a1, %hi(D_800969DC)
/* 3D0C0 80061CC0 24A569DC */  addiu     $a1, $a1, %lo(D_800969DC)
/* 3D0C4 80061CC4 24060001 */  addiu     $a2, $zero, 0x1
/* 3D0C8 80061CC8 AFBF001C */  sw        $ra, 0x1C($sp)
/* 3D0CC 80061CCC 0C0198FC */  jal       osCreateMesgQueue
/* 3D0D0 80061CD0 AFB00018 */   sw       $s0, 0x18($sp)
/* 3D0D4 80061CD4 3C10800D */  lui       $s0, %hi(D_800D58BC)
/* 3D0D8 80061CD8 261058BC */  addiu     $s0, $s0, %lo(D_800D58BC)
/* 3D0DC 80061CDC 8E020000 */  lw        $v0, 0x0($s0)
/* 3D0E0 80061CE0 3C03A800 */  lui       $v1, (0xA8000000 >> 16)
/* 3D0E4 80061CE4 10430030 */  beq       $v0, $v1, .LPAL_80061DA8
/* 3D0E8 80061CE8 26040008 */   addiu    $a0, $s0, 0x8
/* 3D0EC 80061CEC 24020008 */  addiu     $v0, $zero, 0x8
/* 3D0F0 80061CF0 3C01800D */  lui       $at, %hi(D_800D58B4)
/* 3D0F4 80061CF4 A02258B4 */  sb        $v0, %lo(D_800D58B4)($at)
/* 3D0F8 80061CF8 24020005 */  addiu     $v0, $zero, 0x5
/* 3D0FC 80061CFC AE030000 */  sw        $v1, 0x0($s0)
/* 3D100 80061D00 3C01800D */  lui       $at, %hi(D_800D58B5)
/* 3D104 80061D04 A02258B5 */  sb        $v0, %lo(D_800D58B5)($at)
/* 3D108 80061D08 2402000C */  addiu     $v0, $zero, 0xC
/* 3D10C 80061D0C 3C01800D */  lui       $at, %hi(D_800D58B8)
/* 3D110 80061D10 A02258B8 */  sb        $v0, %lo(D_800D58B8)($at)
/* 3D114 80061D14 2402000F */  addiu     $v0, $zero, 0xF
/* 3D118 80061D18 3C01800D */  lui       $at, %hi(D_800D58B6)
/* 3D11C 80061D1C A02258B6 */  sb        $v0, %lo(D_800D58B6)($at)
/* 3D120 80061D20 24020002 */  addiu     $v0, $zero, 0x2
/* 3D124 80061D24 3C01800D */  lui       $at, %hi(D_800D58B7)
/* 3D128 80061D28 A02258B7 */  sb        $v0, %lo(D_800D58B7)($at)
/* 3D12C 80061D2C 24020001 */  addiu     $v0, $zero, 0x1
/* 3D130 80061D30 3C01800D */  lui       $at, %hi(D_800D58B9)
/* 3D134 80061D34 A02258B9 */  sb        $v0, %lo(D_800D58B9)($at)
/* 3D138 80061D38 3C01800D */  lui       $at, %hi(D_800D58C0)
/* 3D13C 80061D3C AC2058C0 */  sw        $zero, %lo(D_800D58C0)($at)
/* 3D140 80061D40 0C0195F8 */  jal       bzero
/* 3D144 80061D44 24050060 */   addiu    $a1, $zero, 0x60
/* 3D148 80061D48 0C01858C */  jal       osEPiLinkHandle
/* 3D14C 80061D4C 2604FFF4 */   addiu    $a0, $s0, -0xC
/* 3D150 80061D50 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D154 80061D54 0C018770 */  jal       osFlashReadId
/* 3D158 80061D58 27A50014 */   addiu    $a1, $sp, 0x14
/* 3D15C 80061D5C 3C0200C2 */  lui       $v0, (0xC2001E >> 16)
/* 3D160 80061D60 3442001E */  ori       $v0, $v0, (0xC2001E & 0xFFFF)
/* 3D164 80061D64 8FA40014 */  lw        $a0, 0x14($sp)
/* 3D168 80061D68 3C0300C2 */  lui       $v1, (0xC20001 >> 16)
/* 3D16C 80061D6C 34630001 */  ori       $v1, $v1, (0xC20001 & 0xFFFF)
/* 3D170 80061D70 00821026 */  xor       $v0, $a0, $v0
/* 3D174 80061D74 2C420001 */  sltiu     $v0, $v0, 0x1
/* 3D178 80061D78 00831826 */  xor       $v1, $a0, $v1
/* 3D17C 80061D7C 2C630001 */  sltiu     $v1, $v1, 0x1
/* 3D180 80061D80 00431025 */  or        $v0, $v0, $v1
/* 3D184 80061D84 14400003 */  bnez      $v0, .LPAL_80061D94
/* 3D188 80061D88 3C0200C2 */   lui      $v0, (0xC20000 >> 16)
/* 3D18C 80061D8C 14820004 */  bne       $a0, $v0, .LPAL_80061DA0
/* 3D190 80061D90 24020001 */   addiu    $v0, $zero, 0x1
.LPAL_80061D94:
/* 3D194 80061D94 3C018009 */  lui       $at, %hi(D_80096990)
/* 3D198 80061D98 0801876A */  j         .LPAL_80061DA8
/* 3D19C 80061D9C AC206990 */   sw       $zero, %lo(D_80096990)($at)
.LPAL_80061DA0:
/* 3D1A0 80061DA0 3C018009 */  lui       $at, %hi(D_80096990)
/* 3D1A4 80061DA4 AC226990 */  sw        $v0, %lo(D_80096990)($at)
.LPAL_80061DA8:
/* 3D1A8 80061DA8 3C02800D */  lui       $v0, %hi(D_800D58B0)
/* 3D1AC 80061DAC 244258B0 */  addiu     $v0, $v0, %lo(D_800D58B0)
/* 3D1B0 80061DB0 8FBF001C */  lw        $ra, 0x1C($sp)
/* 3D1B4 80061DB4 8FB00018 */  lw        $s0, 0x18($sp)
/* 3D1B8 80061DB8 03E00008 */  jr        $ra
/* 3D1BC 80061DBC 27BD0020 */   addiu    $sp, $sp, 0x20
