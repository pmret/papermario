.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_partners_init
/* 13F420 8024C0E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 13F424 8024C0E4 AFB40020 */  sw        $s4, 0x20($sp)
/* 13F428 8024C0E8 0080A02D */  daddu     $s4, $a0, $zero
/* 13F42C 8024C0EC AFBF0024 */  sw        $ra, 0x24($sp)
/* 13F430 8024C0F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 13F434 8024C0F4 AFB20018 */  sw        $s2, 0x18($sp)
/* 13F438 8024C0F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 13F43C 8024C0FC 0C039D59 */  jal       get_player_data
/* 13F440 8024C100 AFB00010 */   sw       $s0, 0x10($sp)
/* 13F444 8024C104 0040982D */  daddu     $s3, $v0, $zero
/* 13F448 8024C108 3C028027 */  lui       $v0, %hi(D_802706B0)
/* 13F44C 8024C10C 244206B0 */  addiu     $v0, $v0, %lo(D_802706B0)
/* 13F450 8024C110 0000802D */  daddu     $s0, $zero, $zero
/* 13F454 8024C114 3C068027 */  lui       $a2, %hi(D_80270680)
/* 13F458 8024C118 24C60680 */  addiu     $a2, $a2, %lo(D_80270680)
/* 13F45C 8024C11C 0040282D */  daddu     $a1, $v0, $zero
/* 13F460 8024C120 3C048025 */  lui       $a0, %hi(D_8024F6B0)
/* 13F464 8024C124 2484F6B0 */  addiu     $a0, $a0, %lo(D_8024F6B0)
/* 13F468 8024C128 AC400000 */  sw        $zero, ($v0)
.L8024C12C:
/* 13F46C 8024C12C 8C820000 */  lw        $v0, ($a0)
/* 13F470 8024C130 000210C0 */  sll       $v0, $v0, 3
/* 13F474 8024C134 02621021 */  addu      $v0, $s3, $v0
/* 13F478 8024C138 90420014 */  lbu       $v0, 0x14($v0)
/* 13F47C 8024C13C 50400008 */  beql      $v0, $zero, .L8024C160
/* 13F480 8024C140 26100001 */   addiu    $s0, $s0, 1
/* 13F484 8024C144 8CA30000 */  lw        $v1, ($a1)
/* 13F488 8024C148 00031080 */  sll       $v0, $v1, 2
/* 13F48C 8024C14C 00461021 */  addu      $v0, $v0, $a2
/* 13F490 8024C150 24630001 */  addiu     $v1, $v1, 1
/* 13F494 8024C154 AC500000 */  sw        $s0, ($v0)
/* 13F498 8024C158 ACA30000 */  sw        $v1, ($a1)
/* 13F49C 8024C15C 26100001 */  addiu     $s0, $s0, 1
.L8024C160:
/* 13F4A0 8024C160 2A020008 */  slti      $v0, $s0, 8
/* 13F4A4 8024C164 1440FFF1 */  bnez      $v0, .L8024C12C
/* 13F4A8 8024C168 24840004 */   addiu    $a0, $a0, 4
/* 13F4AC 8024C16C 3C028027 */  lui       $v0, %hi(D_802706B0)
/* 13F4B0 8024C170 8C4206B0 */  lw        $v0, %lo(D_802706B0)($v0)
/* 13F4B4 8024C174 1440000A */  bnez      $v0, .L8024C1A0
/* 13F4B8 8024C178 0000802D */   daddu    $s0, $zero, $zero
/* 13F4BC 8024C17C 24040022 */  addiu     $a0, $zero, 0x22
/* 13F4C0 8024C180 0C051F9F */  jal       set_window_update
/* 13F4C4 8024C184 24050002 */   addiu    $a1, $zero, 2
/* 13F4C8 8024C188 080930C6 */  j         .L8024C318
/* 13F4CC 8024C18C A2800000 */   sb       $zero, ($s4)
.L8024C190:
/* 13F4D0 8024C190 3C018027 */  lui       $at, %hi(D_802706A0)
/* 13F4D4 8024C194 AC3006A0 */  sw        $s0, %lo(D_802706A0)($at)
/* 13F4D8 8024C198 080930A6 */  j         .L8024C298
/* 13F4DC 8024C19C 00000000 */   nop
.L8024C1A0:
/* 13F4E0 8024C1A0 3C128027 */  lui       $s2, %hi(D_80270660)
/* 13F4E4 8024C1A4 26520660 */  addiu     $s2, $s2, %lo(D_80270660)
/* 13F4E8 8024C1A8 3C118025 */  lui       $s1, %hi(D_8024F630)
/* 13F4EC 8024C1AC 2631F630 */  addiu     $s1, $s1, %lo(D_8024F630)
.L8024C1B0:
/* 13F4F0 8024C1B0 0220282D */  daddu     $a1, $s1, $zero
/* 13F4F4 8024C1B4 8E240000 */  lw        $a0, ($s1)
/* 13F4F8 8024C1B8 26310010 */  addiu     $s1, $s1, 0x10
/* 13F4FC 8024C1BC 0C0B783B */  jal       spr_load_npc_sprite
/* 13F500 8024C1C0 26100001 */   addiu    $s0, $s0, 1
/* 13F504 8024C1C4 AE420000 */  sw        $v0, ($s2)
/* 13F508 8024C1C8 2A020008 */  slti      $v0, $s0, 8
/* 13F50C 8024C1CC 1440FFF8 */  bnez      $v0, .L8024C1B0
/* 13F510 8024C1D0 26520004 */   addiu    $s2, $s2, 4
/* 13F514 8024C1D4 0000802D */  daddu     $s0, $zero, $zero
/* 13F518 8024C1D8 3C128027 */  lui       $s2, %hi(D_80270640)
/* 13F51C 8024C1DC 26520640 */  addiu     $s2, $s2, %lo(D_80270640)
/* 13F520 8024C1E0 3C118025 */  lui       $s1, %hi(D_8024F600)
/* 13F524 8024C1E4 2631F600 */  addiu     $s1, $s1, %lo(D_8024F600)
.L8024C1E8:
/* 13F528 8024C1E8 8E240000 */  lw        $a0, ($s1)
/* 13F52C 8024C1EC 26310004 */  addiu     $s1, $s1, 4
/* 13F530 8024C1F0 0C050529 */  jal       create_hud_element
/* 13F534 8024C1F4 26100001 */   addiu    $s0, $s0, 1
/* 13F538 8024C1F8 0040202D */  daddu     $a0, $v0, $zero
/* 13F53C 8024C1FC 24050080 */  addiu     $a1, $zero, 0x80
/* 13F540 8024C200 0C051280 */  jal       set_hud_element_flags
/* 13F544 8024C204 AE440000 */   sw       $a0, ($s2)
/* 13F548 8024C208 2A020008 */  slti      $v0, $s0, 8
/* 13F54C 8024C20C 1440FFF6 */  bnez      $v0, .L8024C1E8
/* 13F550 8024C210 26520004 */   addiu    $s2, $s2, 4
/* 13F554 8024C214 24100004 */  addiu     $s0, $zero, 4
/* 13F558 8024C218 3C028025 */  lui       $v0, %hi(D_8024F858)
/* 13F55C 8024C21C 2442F858 */  addiu     $v0, $v0, %lo(D_8024F858)
.L8024C220:
/* 13F560 8024C220 AC540010 */  sw        $s4, 0x10($v0)
/* 13F564 8024C224 2610FFFF */  addiu     $s0, $s0, -1
/* 13F568 8024C228 0601FFFD */  bgez      $s0, .L8024C220
/* 13F56C 8024C22C 2442FFDC */   addiu    $v0, $v0, -0x24
/* 13F570 8024C230 3C048025 */  lui       $a0, %hi(D_8024F7C8)
/* 13F574 8024C234 2484F7C8 */  addiu     $a0, $a0, %lo(D_8024F7C8)
/* 13F578 8024C238 0C051FCC */  jal       setup_pause_menu_tab
/* 13F57C 8024C23C 24050005 */   addiu    $a1, $zero, 5
/* 13F580 8024C240 3C028027 */  lui       $v0, %hi(D_802706B0)
/* 13F584 8024C244 8C4206B0 */  lw        $v0, %lo(D_802706B0)($v0)
/* 13F588 8024C248 3C018027 */  lui       $at, %hi(D_802706A0)
/* 13F58C 8024C24C AC2006A0 */  sw        $zero, %lo(D_802706A0)($at)
/* 13F590 8024C250 18400011 */  blez      $v0, .L8024C298
/* 13F594 8024C254 0000802D */   daddu    $s0, $zero, $zero
/* 13F598 8024C258 82650012 */  lb        $a1, 0x12($s3)
/* 13F59C 8024C25C 3C068025 */  lui       $a2, %hi(D_8024F6B0)
/* 13F5A0 8024C260 24C6F6B0 */  addiu     $a2, $a2, %lo(D_8024F6B0)
/* 13F5A4 8024C264 0040202D */  daddu     $a0, $v0, $zero
/* 13F5A8 8024C268 3C038027 */  lui       $v1, %hi(D_80270680)
/* 13F5AC 8024C26C 24630680 */  addiu     $v1, $v1, %lo(D_80270680)
.L8024C270:
/* 13F5B0 8024C270 8C620000 */  lw        $v0, ($v1)
/* 13F5B4 8024C274 00021080 */  sll       $v0, $v0, 2
/* 13F5B8 8024C278 00461021 */  addu      $v0, $v0, $a2
/* 13F5BC 8024C27C 8C420000 */  lw        $v0, ($v0)
/* 13F5C0 8024C280 10A2FFC3 */  beq       $a1, $v0, .L8024C190
/* 13F5C4 8024C284 00000000 */   nop
/* 13F5C8 8024C288 26100001 */  addiu     $s0, $s0, 1
/* 13F5CC 8024C28C 0204102A */  slt       $v0, $s0, $a0
/* 13F5D0 8024C290 1440FFF7 */  bnez      $v0, .L8024C270
/* 13F5D4 8024C294 24630004 */   addiu    $v1, $v1, 4
.L8024C298:
/* 13F5D8 8024C298 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13F5DC 8024C29C 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13F5E0 8024C2A0 00021840 */  sll       $v1, $v0, 1
/* 13F5E4 8024C2A4 00621821 */  addu      $v1, $v1, $v0
/* 13F5E8 8024C2A8 00031100 */  sll       $v0, $v1, 4
/* 13F5EC 8024C2AC 00431023 */  subu      $v0, $v0, $v1
/* 13F5F0 8024C2B0 3C038027 */  lui       $v1, %hi(D_802706B0)
/* 13F5F4 8024C2B4 8C6306B0 */  lw        $v1, %lo(D_802706B0)($v1)
/* 13F5F8 8024C2B8 000210C0 */  sll       $v0, $v0, 3
/* 13F5FC 8024C2BC 14600002 */  bnez      $v1, .L8024C2C8
/* 13F600 8024C2C0 0043001A */   div      $zero, $v0, $v1
/* 13F604 8024C2C4 0007000D */  break     7
.L8024C2C8:
/* 13F608 8024C2C8 2401FFFF */   addiu    $at, $zero, -1
/* 13F60C 8024C2CC 14610004 */  bne       $v1, $at, .L8024C2E0
/* 13F610 8024C2D0 3C018000 */   lui      $at, 0x8000
/* 13F614 8024C2D4 14410002 */  bne       $v0, $at, .L8024C2E0
/* 13F618 8024C2D8 00000000 */   nop
/* 13F61C 8024C2DC 0006000D */  break     6
.L8024C2E0:
/* 13F620 8024C2E0 00001012 */   mflo     $v0
/* 13F624 8024C2E4 3C018027 */  lui       $at, %hi(D_802706A4)
/* 13F628 8024C2E8 AC2006A4 */  sw        $zero, %lo(D_802706A4)($at)
/* 13F62C 8024C2EC 3C018027 */  lui       $at, %hi(D_802706AC)
/* 13F630 8024C2F0 AC2006AC */  sw        $zero, %lo(D_802706AC)($at)
/* 13F634 8024C2F4 44820000 */  mtc1      $v0, $f0
/* 13F638 8024C2F8 00000000 */  nop
/* 13F63C 8024C2FC 46800020 */  cvt.s.w   $f0, $f0
/* 13F640 8024C300 3C018027 */  lui       $at, %hi(D_802706A8)
/* 13F644 8024C304 E42006A8 */  swc1      $f0, %lo(D_802706A8)($at)
/* 13F648 8024C308 0C092B78 */  jal       pause_partners_load_portrait
/* 13F64C 8024C30C 0000202D */   daddu    $a0, $zero, $zero
/* 13F650 8024C310 24020001 */  addiu     $v0, $zero, 1
/* 13F654 8024C314 A2820000 */  sb        $v0, ($s4)
.L8024C318:
/* 13F658 8024C318 8FBF0024 */  lw        $ra, 0x24($sp)
/* 13F65C 8024C31C 8FB40020 */  lw        $s4, 0x20($sp)
/* 13F660 8024C320 8FB3001C */  lw        $s3, 0x1c($sp)
/* 13F664 8024C324 8FB20018 */  lw        $s2, 0x18($sp)
/* 13F668 8024C328 8FB10014 */  lw        $s1, 0x14($sp)
/* 13F66C 8024C32C 8FB00010 */  lw        $s0, 0x10($sp)
/* 13F670 8024C330 03E00008 */  jr        $ra
/* 13F674 8024C334 27BD0028 */   addiu    $sp, $sp, 0x28
