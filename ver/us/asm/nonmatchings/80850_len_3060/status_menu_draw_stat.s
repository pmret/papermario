.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel status_menu_draw_stat
/* 812E4 800E7E34 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 812E8 800E7E38 AFB40030 */  sw        $s4, 0x30($sp)
/* 812EC 800E7E3C 0080A02D */  daddu     $s4, $a0, $zero
/* 812F0 800E7E40 AFB00020 */  sw        $s0, 0x20($sp)
/* 812F4 800E7E44 00A0802D */  daddu     $s0, $a1, $zero
/* 812F8 800E7E48 AFB10024 */  sw        $s1, 0x24($sp)
/* 812FC 800E7E4C 00C0882D */  daddu     $s1, $a2, $zero
/* 81300 800E7E50 AFB3002C */  sw        $s3, 0x2c($sp)
/* 81304 800E7E54 00E0982D */  daddu     $s3, $a3, $zero
/* 81308 800E7E58 AFB60038 */  sw        $s6, 0x38($sp)
/* 8130C 800E7E5C 24160002 */  addiu     $s6, $zero, 2
/* 81310 800E7E60 AFB20028 */  sw        $s2, 0x28($sp)
/* 81314 800E7E64 0000902D */  daddu     $s2, $zero, $zero
/* 81318 800E7E68 AFB50034 */  sw        $s5, 0x34($sp)
/* 8131C 800E7E6C 8FB50058 */  lw        $s5, 0x58($sp)
/* 81320 800E7E70 3C05800F */  lui       $a1, %hi(D_800F7FAC)
/* 81324 800E7E74 8CA57FAC */  lw        $a1, %lo(D_800F7FAC)($a1)
/* 81328 800E7E78 26080008 */  addiu     $t0, $s0, 8
/* 8132C 800E7E7C AFA80018 */  sw        $t0, 0x18($sp)
/* 81330 800E7E80 26280008 */  addiu     $t0, $s1, 8
/* 81334 800E7E84 AFBF0044 */  sw        $ra, 0x44($sp)
/* 81338 800E7E88 AFBE0040 */  sw        $fp, 0x40($sp)
/* 8133C 800E7E8C AFB7003C */  sw        $s7, 0x3c($sp)
/* 81340 800E7E90 0C0511FF */  jal       set_hud_element_anim
/* 81344 800E7E94 AFA8001C */   sw       $t0, 0x1c($sp)
/* 81348 800E7E98 0280202D */  daddu     $a0, $s4, $zero
/* 8134C 800E7E9C 26050016 */  addiu     $a1, $s0, 0x16
/* 81350 800E7EA0 0C051261 */  jal       set_hud_element_render_pos
/* 81354 800E7EA4 26260009 */   addiu    $a2, $s1, 9
/* 81358 800E7EA8 0280202D */  daddu     $a0, $s4, $zero
/* 8135C 800E7EAC 0C05128B */  jal       clear_hud_element_flags
/* 81360 800E7EB0 02C0282D */   daddu    $a1, $s6, $zero
/* 81364 800E7EB4 0C0511F1 */  jal       draw_hud_element_2
/* 81368 800E7EB8 0280202D */   daddu    $a0, $s4, $zero
/* 8136C 800E7EBC 3C066666 */  lui       $a2, 0x6666
/* 81370 800E7EC0 34C66667 */  ori       $a2, $a2, 0x6667
/* 81374 800E7EC4 27A50010 */  addiu     $a1, $sp, 0x10
.L800E7EC8:
/* 81378 800E7EC8 02660018 */  mult      $s3, $a2
/* 8137C 800E7ECC 02D22023 */  subu      $a0, $s6, $s2
/* 81380 800E7ED0 26520001 */  addiu     $s2, $s2, 1
/* 81384 800E7ED4 001317C3 */  sra       $v0, $s3, 0x1f
/* 81388 800E7ED8 00852021 */  addu      $a0, $a0, $a1
/* 8138C 800E7EDC 00004010 */  mfhi      $t0
/* 81390 800E7EE0 00081883 */  sra       $v1, $t0, 2
/* 81394 800E7EE4 00621023 */  subu      $v0, $v1, $v0
/* 81398 800E7EE8 0040182D */  daddu     $v1, $v0, $zero
/* 8139C 800E7EEC 00031080 */  sll       $v0, $v1, 2
/* 813A0 800E7EF0 00431021 */  addu      $v0, $v0, $v1
/* 813A4 800E7EF4 00021040 */  sll       $v0, $v0, 1
/* 813A8 800E7EF8 02621023 */  subu      $v0, $s3, $v0
/* 813AC 800E7EFC A082FFFF */  sb        $v0, -1($a0)
/* 813B0 800E7F00 0256102A */  slt       $v0, $s2, $s6
/* 813B4 800E7F04 1440FFF0 */  bnez      $v0, .L800E7EC8
/* 813B8 800E7F08 0060982D */   daddu    $s3, $v1, $zero
/* 813BC 800E7F0C 8FB00018 */  lw        $s0, 0x18($sp)
/* 813C0 800E7F10 0000882D */  daddu     $s1, $zero, $zero
/* 813C4 800E7F14 8FB3001C */  lw        $s3, 0x1c($sp)
/* 813C8 800E7F18 12C00020 */  beqz      $s6, .L800E7F9C
/* 813CC 800E7F1C 0220902D */   daddu    $s2, $s1, $zero
/* 813D0 800E7F20 27BE0010 */  addiu     $fp, $sp, 0x10
/* 813D4 800E7F24 26D7FFFF */  addiu     $s7, $s6, -1
.L800E7F28:
/* 813D8 800E7F28 03D21021 */  addu      $v0, $fp, $s2
/* 813DC 800E7F2C 80420000 */  lb        $v0, ($v0)
/* 813E0 800E7F30 54400006 */  bnel      $v0, $zero, .L800E7F4C
/* 813E4 800E7F34 24110001 */   addiu    $s1, $zero, 1
/* 813E8 800E7F38 56200004 */  bnel      $s1, $zero, .L800E7F4C
/* 813EC 800E7F3C 24110001 */   addiu    $s1, $zero, 1
/* 813F0 800E7F40 56570013 */  bnel      $s2, $s7, .L800E7F90
/* 813F4 800E7F44 26520001 */   addiu    $s2, $s2, 1
/* 813F8 800E7F48 24110001 */  addiu     $s1, $zero, 1
.L800E7F4C:
/* 813FC 800E7F4C 00021080 */  sll       $v0, $v0, 2
/* 81400 800E7F50 3C08800F */  lui       $t0, %hi(D_800F7F80)
/* 81404 800E7F54 25087F80 */  addiu     $t0, $t0, %lo(D_800F7F80)
/* 81408 800E7F58 00481021 */  addu      $v0, $v0, $t0
/* 8140C 800E7F5C 8C450000 */  lw        $a1, ($v0)
/* 81410 800E7F60 0C0511FF */  jal       set_hud_element_anim
/* 81414 800E7F64 0280202D */   daddu    $a0, $s4, $zero
/* 81418 800E7F68 0280202D */  daddu     $a0, $s4, $zero
/* 8141C 800E7F6C 0200282D */  daddu     $a1, $s0, $zero
/* 81420 800E7F70 0C051261 */  jal       set_hud_element_render_pos
/* 81424 800E7F74 0260302D */   daddu    $a2, $s3, $zero
/* 81428 800E7F78 0280202D */  daddu     $a0, $s4, $zero
/* 8142C 800E7F7C 0C05128B */  jal       clear_hud_element_flags
/* 81430 800E7F80 24050002 */   addiu    $a1, $zero, 2
/* 81434 800E7F84 0C0511F1 */  jal       draw_hud_element_2
/* 81438 800E7F88 0280202D */   daddu    $a0, $s4, $zero
/* 8143C 800E7F8C 26520001 */  addiu     $s2, $s2, 1
.L800E7F90:
/* 81440 800E7F90 0256102A */  slt       $v0, $s2, $s6
/* 81444 800E7F94 1440FFE4 */  bnez      $v0, .L800E7F28
/* 81448 800E7F98 26100008 */   addiu    $s0, $s0, 8
.L800E7F9C:
/* 8144C 800E7F9C 12C00014 */  beqz      $s6, .L800E7FF0
/* 81450 800E7FA0 0000902D */   daddu    $s2, $zero, $zero
/* 81454 800E7FA4 27A60010 */  addiu     $a2, $sp, 0x10
/* 81458 800E7FA8 3C056666 */  lui       $a1, 0x6666
/* 8145C 800E7FAC 34A56667 */  ori       $a1, $a1, 0x6667
.L800E7FB0:
/* 81460 800E7FB0 02A50018 */  mult      $s5, $a1
/* 81464 800E7FB4 02D22023 */  subu      $a0, $s6, $s2
/* 81468 800E7FB8 26520001 */  addiu     $s2, $s2, 1
/* 8146C 800E7FBC 00862021 */  addu      $a0, $a0, $a2
/* 81470 800E7FC0 001517C3 */  sra       $v0, $s5, 0x1f
/* 81474 800E7FC4 00004010 */  mfhi      $t0
/* 81478 800E7FC8 00081883 */  sra       $v1, $t0, 2
/* 8147C 800E7FCC 00621823 */  subu      $v1, $v1, $v0
/* 81480 800E7FD0 00031080 */  sll       $v0, $v1, 2
/* 81484 800E7FD4 00431021 */  addu      $v0, $v0, $v1
/* 81488 800E7FD8 00021040 */  sll       $v0, $v0, 1
/* 8148C 800E7FDC 02A21023 */  subu      $v0, $s5, $v0
/* 81490 800E7FE0 A082FFFF */  sb        $v0, -1($a0)
/* 81494 800E7FE4 0256102A */  slt       $v0, $s2, $s6
/* 81498 800E7FE8 1440FFF1 */  bnez      $v0, .L800E7FB0
/* 8149C 800E7FEC 0060A82D */   daddu    $s5, $v1, $zero
.L800E7FF0:
/* 814A0 800E7FF0 0000882D */  daddu     $s1, $zero, $zero
/* 814A4 800E7FF4 0220902D */  daddu     $s2, $s1, $zero
/* 814A8 800E7FF8 8FA80018 */  lw        $t0, 0x18($sp)
/* 814AC 800E7FFC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 814B0 800E8000 12C00020 */  beqz      $s6, .L800E8084
/* 814B4 800E8004 2510001A */   addiu    $s0, $t0, 0x1a
/* 814B8 800E8008 27B70010 */  addiu     $s7, $sp, 0x10
/* 814BC 800E800C 26D5FFFF */  addiu     $s5, $s6, -1
/* 814C0 800E8010 3C1E800F */  lui       $fp, %hi(D_800F7F80)
/* 814C4 800E8014 27DE7F80 */  addiu     $fp, $fp, %lo(D_800F7F80)
.L800E8018:
/* 814C8 800E8018 02F21021 */  addu      $v0, $s7, $s2
/* 814CC 800E801C 80420000 */  lb        $v0, ($v0)
/* 814D0 800E8020 54400006 */  bnel      $v0, $zero, .L800E803C
/* 814D4 800E8024 24110001 */   addiu    $s1, $zero, 1
/* 814D8 800E8028 56200004 */  bnel      $s1, $zero, .L800E803C
/* 814DC 800E802C 24110001 */   addiu    $s1, $zero, 1
/* 814E0 800E8030 56550011 */  bnel      $s2, $s5, .L800E8078
/* 814E4 800E8034 26520001 */   addiu    $s2, $s2, 1
/* 814E8 800E8038 24110001 */  addiu     $s1, $zero, 1
.L800E803C:
/* 814EC 800E803C 00021080 */  sll       $v0, $v0, 2
/* 814F0 800E8040 005E1021 */  addu      $v0, $v0, $fp
/* 814F4 800E8044 8C450000 */  lw        $a1, ($v0)
/* 814F8 800E8048 0C0511FF */  jal       set_hud_element_anim
/* 814FC 800E804C 0280202D */   daddu    $a0, $s4, $zero
/* 81500 800E8050 0280202D */  daddu     $a0, $s4, $zero
/* 81504 800E8054 0200282D */  daddu     $a1, $s0, $zero
/* 81508 800E8058 0C051261 */  jal       set_hud_element_render_pos
/* 8150C 800E805C 0260302D */   daddu    $a2, $s3, $zero
/* 81510 800E8060 0280202D */  daddu     $a0, $s4, $zero
/* 81514 800E8064 0C05128B */  jal       clear_hud_element_flags
/* 81518 800E8068 24050002 */   addiu    $a1, $zero, 2
/* 8151C 800E806C 0C0511F1 */  jal       draw_hud_element_2
/* 81520 800E8070 0280202D */   daddu    $a0, $s4, $zero
/* 81524 800E8074 26520001 */  addiu     $s2, $s2, 1
.L800E8078:
/* 81528 800E8078 0256102A */  slt       $v0, $s2, $s6
/* 8152C 800E807C 1440FFE6 */  bnez      $v0, .L800E8018
/* 81530 800E8080 26100008 */   addiu    $s0, $s0, 8
.L800E8084:
/* 81534 800E8084 8FBF0044 */  lw        $ra, 0x44($sp)
/* 81538 800E8088 8FBE0040 */  lw        $fp, 0x40($sp)
/* 8153C 800E808C 8FB7003C */  lw        $s7, 0x3c($sp)
/* 81540 800E8090 8FB60038 */  lw        $s6, 0x38($sp)
/* 81544 800E8094 8FB50034 */  lw        $s5, 0x34($sp)
/* 81548 800E8098 8FB40030 */  lw        $s4, 0x30($sp)
/* 8154C 800E809C 8FB3002C */  lw        $s3, 0x2c($sp)
/* 81550 800E80A0 8FB20028 */  lw        $s2, 0x28($sp)
/* 81554 800E80A4 8FB10024 */  lw        $s1, 0x24($sp)
/* 81558 800E80A8 8FB00020 */  lw        $s0, 0x20($sp)
/* 8155C 800E80AC 03E00008 */  jr        $ra
/* 81560 800E80B0 27BD0048 */   addiu    $sp, $sp, 0x48
