.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A2684
/* 417414 802A2684 3C03802B */  lui       $v1, %hi(D_802AD4A8)
/* 417418 802A2688 2463D4A8 */  addiu     $v1, $v1, %lo(D_802AD4A8)
/* 41741C 802A268C 3C05802B */  lui       $a1, %hi(battle_menu_moveOptionCount)
/* 417420 802A2690 24A5D4A4 */  addiu     $a1, $a1, %lo(battle_menu_moveOptionCount)
/* 417424 802A2694 8C620000 */  lw        $v0, ($v1)
/* 417428 802A2698 8CA70000 */  lw        $a3, ($a1)
/* 41742C 802A269C 0047102A */  slt       $v0, $v0, $a3
/* 417430 802A26A0 14400002 */  bnez      $v0, .L802A26AC
/* 417434 802A26A4 24E2FFFF */   addiu    $v0, $a3, -1
/* 417438 802A26A8 AC620000 */  sw        $v0, ($v1)
.L802A26AC:
/* 41743C 802A26AC 3C01802B */  lui       $at, %hi(battle_menu_moveState)
/* 417440 802A26B0 A020D108 */  sb        $zero, %lo(battle_menu_moveState)($at)
/* 417444 802A26B4 90640003 */  lbu       $a0, 3($v1)
/* 417448 802A26B8 3C03802B */  lui       $v1, %hi(battle_menu_moveScrollLine)
/* 41744C 802A26BC 2463D10C */  addiu     $v1, $v1, %lo(battle_menu_moveScrollLine)
/* 417450 802A26C0 A0600000 */  sb        $zero, ($v1)
/* 417454 802A26C4 3C01802B */  lui       $at, %hi(battle_menu_moveCursorPos)
/* 417458 802A26C8 A024D109 */  sb        $a0, %lo(battle_menu_moveCursorPos)($at)
/* 41745C 802A26CC 3C01802B */  lui       $at, %hi(D_802AD10A)
/* 417460 802A26D0 A024D10A */  sb        $a0, %lo(D_802AD10A)($at)
/* 417464 802A26D4 90A60003 */  lbu       $a2, 3($a1)
/* 417468 802A26D8 3C09802B */  lui       $t1, %hi(D_802AD10E)
/* 41746C 802A26DC 2529D10E */  addiu     $t1, $t1, %lo(D_802AD10E)
/* 417470 802A26E0 00061600 */  sll       $v0, $a2, 0x18
/* 417474 802A26E4 00021603 */  sra       $v0, $v0, 0x18
/* 417478 802A26E8 28420007 */  slti      $v0, $v0, 7
/* 41747C 802A26EC 14400003 */  bnez      $v0, .L802A26FC
/* 417480 802A26F0 A1260000 */   sb       $a2, ($t1)
/* 417484 802A26F4 24020006 */  addiu     $v0, $zero, 6
/* 417488 802A26F8 A1220000 */  sb        $v0, ($t1)
.L802A26FC:
/* 41748C 802A26FC 3C08802B */  lui       $t0, %hi(D_802AD10D)
/* 417490 802A2700 2508D10D */  addiu     $t0, $t0, %lo(D_802AD10D)
/* 417494 802A2704 24020006 */  addiu     $v0, $zero, 6
/* 417498 802A2708 A1020000 */  sb        $v0, ($t0)
/* 41749C 802A270C 28E20006 */  slti      $v0, $a3, 6
/* 4174A0 802A2710 54400001 */  bnel      $v0, $zero, .L802A2718
/* 4174A4 802A2714 A1060000 */   sb       $a2, ($t0)
.L802A2718:
/* 4174A8 802A2718 240200FF */  addiu     $v0, $zero, 0xff
/* 4174AC 802A271C 3C01802B */  lui       $at, %hi(battle_menu_moveTextOpacity)
/* 4174B0 802A2720 A422D116 */  sh        $v0, %lo(battle_menu_moveTextOpacity)($at)
/* 4174B4 802A2724 24020001 */  addiu     $v0, $zero, 1
/* 4174B8 802A2728 3C01802B */  lui       $at, %hi(D_802AD10F)
/* 4174BC 802A272C A022D10F */  sb        $v0, %lo(D_802AD10F)($at)
/* 4174C0 802A2730 00041600 */  sll       $v0, $a0, 0x18
/* 4174C4 802A2734 00022E03 */  sra       $a1, $v0, 0x18
/* 4174C8 802A2738 04A20001 */  bltzl     $a1, .L802A2740
/* 4174CC 802A273C A0640000 */   sb       $a0, ($v1)
.L802A2740:
/* 4174D0 802A2740 81020000 */  lb        $v0, ($t0)
/* 4174D4 802A2744 00A2102A */  slt       $v0, $a1, $v0
/* 4174D8 802A2748 14400005 */  bnez      $v0, .L802A2760
/* 4174DC 802A274C 00000000 */   nop
/* 4174E0 802A2750 91220000 */  lbu       $v0, ($t1)
/* 4174E4 802A2754 2442FFFF */  addiu     $v0, $v0, -1
/* 4174E8 802A2758 00821023 */  subu      $v0, $a0, $v0
/* 4174EC 802A275C A0620000 */  sb        $v0, ($v1)
.L802A2760:
/* 4174F0 802A2760 90630000 */  lbu       $v1, ($v1)
/* 4174F4 802A2764 24620006 */  addiu     $v0, $v1, 6
/* 4174F8 802A2768 A1020000 */  sb        $v0, ($t0)
/* 4174FC 802A276C 00021600 */  sll       $v0, $v0, 0x18
/* 417500 802A2770 00021603 */  sra       $v0, $v0, 0x18
/* 417504 802A2774 00E2102A */  slt       $v0, $a3, $v0
/* 417508 802A2778 54400001 */  bnel      $v0, $zero, .L802A2780
/* 41750C 802A277C A1060000 */   sb       $a2, ($t0)
.L802A2780:
/* 417510 802A2780 00031E00 */  sll       $v1, $v1, 0x18
/* 417514 802A2784 00031E03 */  sra       $v1, $v1, 0x18
/* 417518 802A2788 00032023 */  negu      $a0, $v1
/* 41751C 802A278C 00041040 */  sll       $v0, $a0, 1
/* 417520 802A2790 00441021 */  addu      $v0, $v0, $a0
/* 417524 802A2794 00021080 */  sll       $v0, $v0, 2
/* 417528 802A2798 00441021 */  addu      $v0, $v0, $a0
/* 41752C 802A279C 00A31823 */  subu      $v1, $a1, $v1
/* 417530 802A27A0 3C01802B */  lui       $at, %hi(battle_menu_moveScrollOffset)
/* 417534 802A27A4 A422D110 */  sh        $v0, %lo(battle_menu_moveScrollOffset)($at)
/* 417538 802A27A8 00031040 */  sll       $v0, $v1, 1
/* 41753C 802A27AC 00431021 */  addu      $v0, $v0, $v1
/* 417540 802A27B0 00021080 */  sll       $v0, $v0, 2
/* 417544 802A27B4 00431021 */  addu      $v0, $v0, $v1
/* 417548 802A27B8 3C01802B */  lui       $at, %hi(D_802AD112)
/* 41754C 802A27BC A422D112 */  sh        $v0, %lo(D_802AD112)($at)
/* 417550 802A27C0 3C01802B */  lui       $at, %hi(battle_menu_moveOptionActive)
/* 417554 802A27C4 AC20D600 */  sw        $zero, %lo(battle_menu_moveOptionActive)($at)
/* 417558 802A27C8 03E00008 */  jr        $ra
/* 41755C 802A27CC 00000000 */   nop
