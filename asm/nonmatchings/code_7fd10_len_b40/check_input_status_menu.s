.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel check_input_status_menu
/* 8073C 800E728C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 80740 800E7290 0000202D */  daddu     $a0, $zero, $zero
/* 80744 800E7294 3C05F5DE */  lui       $a1, 0xf5de
/* 80748 800E7298 34A50180 */  ori       $a1, $a1, 0x180
/* 8074C 800E729C AFBF0018 */  sw        $ra, 0x18($sp)
/* 80750 800E72A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 80754 800E72A4 0C0B1EAF */  jal       get_variable
/* 80758 800E72A8 AFB00010 */   sw       $s0, 0x10($sp)
/* 8075C 800E72AC 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 80760 800E72B0 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 80764 800E72B4 28420060 */  slti      $v0, $v0, 0x60
/* 80768 800E72B8 10400031 */  beqz      $v0, .L800E7380
/* 8076C 800E72BC 24020021 */   addiu    $v0, $zero, 0x21
/* 80770 800E72C0 822300B4 */  lb        $v1, 0xb4($s1)
/* 80774 800E72C4 10620003 */  beq       $v1, $v0, .L800E72D4
/* 80778 800E72C8 00000000 */   nop      
/* 8077C 800E72CC 08039CB8 */  j         .L800E72E0
/* 80780 800E72D0 8E3000E0 */   lw       $s0, 0xe0($s1)
.L800E72D4:
/* 80784 800E72D4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 80788 800E72D8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8078C 800E72DC 8C500010 */  lw        $s0, 0x10($v0)
.L800E72E0:
/* 80790 800E72E0 0C03A644 */  jal       is_status_menu_visible
/* 80794 800E72E4 00000000 */   nop      
/* 80798 800E72E8 14400013 */  bnez      $v0, .L800E7338
/* 8079C 800E72EC 00000000 */   nop      
/* 807A0 800E72F0 8E2200DC */  lw        $v0, 0xdc($s1)
/* 807A4 800E72F4 30422010 */  andi      $v0, $v0, 0x2010
/* 807A8 800E72F8 14400021 */  bnez      $v0, .L800E7380
/* 807AC 800E72FC 32020008 */   andi     $v0, $s0, 8
/* 807B0 800E7300 1040001F */  beqz      $v0, .L800E7380
/* 807B4 800E7304 00000000 */   nop      
/* 807B8 800E7308 0C03A618 */  jal       func_800E9860
/* 807BC 800E730C 00000000 */   nop      
/* 807C0 800E7310 1040001B */  beqz      $v0, .L800E7380
/* 807C4 800E7314 00000000 */   nop      
/* 807C8 800E7318 0C03A5D8 */  jal       open_status_menu_long
/* 807CC 800E731C 00000000 */   nop      
/* 807D0 800E7320 0C04D07A */  jal       func_801341E8
/* 807D4 800E7324 00000000 */   nop      
/* 807D8 800E7328 14400015 */  bnez      $v0, .L800E7380
/* 807DC 800E732C 24040003 */   addiu    $a0, $zero, 3
/* 807E0 800E7330 08039CDE */  j         .L800E7378
/* 807E4 800E7334 00000000 */   nop      
.L800E7338:
/* 807E8 800E7338 8E2200DC */  lw        $v0, 0xdc($s1)
/* 807EC 800E733C 30422010 */  andi      $v0, $v0, 0x2010
/* 807F0 800E7340 1440000F */  bnez      $v0, .L800E7380
/* 807F4 800E7344 32020008 */   andi     $v0, $s0, 8
/* 807F8 800E7348 1040000D */  beqz      $v0, .L800E7380
/* 807FC 800E734C 00000000 */   nop      
/* 80800 800E7350 0C03A618 */  jal       func_800E9860
/* 80804 800E7354 00000000 */   nop      
/* 80808 800E7358 10400009 */  beqz      $v0, .L800E7380
/* 8080C 800E735C 00000000 */   nop      
/* 80810 800E7360 0C03A5EE */  jal       func_800E97B8
/* 80814 800E7364 00000000 */   nop      
/* 80818 800E7368 0C04D07A */  jal       func_801341E8
/* 8081C 800E736C 00000000 */   nop      
/* 80820 800E7370 14400003 */  bnez      $v0, .L800E7380
/* 80824 800E7374 24040004 */   addiu    $a0, $zero, 4
.L800E7378:
/* 80828 800E7378 0C05272D */  jal       play_sound
/* 8082C 800E737C 00000000 */   nop      
.L800E7380:
/* 80830 800E7380 8FBF0018 */  lw        $ra, 0x18($sp)
/* 80834 800E7384 8FB10014 */  lw        $s1, 0x14($sp)
/* 80838 800E7388 8FB00010 */  lw        $s0, 0x10($sp)
/* 8083C 800E738C 03E00008 */  jr        $ra
/* 80840 800E7390 27BD0020 */   addiu    $sp, $sp, 0x20
/* 80844 800E7394 00000000 */  nop       
/* 80848 800E7398 00000000 */  nop       
/* 8084C 800E739C 00000000 */  nop       
