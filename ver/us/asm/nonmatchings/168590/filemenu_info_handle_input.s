.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_info_handle_input
/* 168884 80248024 3C028025 */  lui       $v0, %hi(D_8024C084)
/* 168888 80248028 8C42C084 */  lw        $v0, %lo(D_8024C084)($v0)
/* 16888C 8024802C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 168890 80248030 AFBF0018 */  sw        $ra, 0x18($sp)
/* 168894 80248034 AFB10014 */  sw        $s1, 0x14($sp)
/* 168898 80248038 3042C000 */  andi      $v0, $v0, 0xc000
/* 16889C 8024803C 10400043 */  beqz      $v0, .L8024814C
/* 1688A0 80248040 AFB00010 */   sw       $s0, 0x10($sp)
/* 1688A4 80248044 3C118025 */  lui       $s1, %hi(D_80249B84)
/* 1688A8 80248048 8E319B84 */  lw        $s1, %lo(D_80249B84)($s1)
/* 1688AC 8024804C 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 1688B0 80248050 A020C098 */  sb        $zero, %lo(D_8024C098_C09918)($at)
/* 1688B4 80248054 82230004 */  lb        $v1, 4($s1)
/* 1688B8 80248058 24020002 */  addiu     $v0, $zero, 2
/* 1688BC 8024805C 10620033 */  beq       $v1, $v0, .L8024812C
/* 1688C0 80248060 28620003 */   slti     $v0, $v1, 3
/* 1688C4 80248064 10400005 */  beqz      $v0, .L8024807C
/* 1688C8 80248068 24020001 */   addiu    $v0, $zero, 1
/* 1688CC 8024806C 10620008 */  beq       $v1, $v0, .L80248090
/* 1688D0 80248070 2404002F */   addiu    $a0, $zero, 0x2f
/* 1688D4 80248074 08092051 */  j         .L80248144
/* 1688D8 80248078 00000000 */   nop
.L8024807C:
/* 1688DC 8024807C 24020004 */  addiu     $v0, $zero, 4
/* 1688E0 80248080 10620017 */  beq       $v1, $v0, .L802480E0
/* 1688E4 80248084 2404002F */   addiu    $a0, $zero, 0x2f
/* 1688E8 80248088 08092051 */  j         .L80248144
/* 1688EC 8024808C 00000000 */   nop
.L80248090:
/* 1688F0 80248090 A2200004 */  sb        $zero, 4($s1)
/* 1688F4 80248094 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_left)
/* 1688F8 80248098 24A533F4 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_left)
/* 1688FC 8024809C 0C051F9F */  jal       set_window_update
/* 168900 802480A0 24040033 */   addiu    $a0, $zero, 0x33
/* 168904 802480A4 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_right)
/* 168908 802480A8 24A53468 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_right)
/* 16890C 802480AC 0C051F9F */  jal       set_window_update
/* 168910 802480B0 24040034 */   addiu    $a0, $zero, 0x34
/* 168914 802480B4 24040035 */  addiu     $a0, $zero, 0x35
/* 168918 802480B8 3C108024 */  lui       $s0, %hi(filemenu_update_show_options_bottom)
/* 16891C 802480BC 261034DC */  addiu     $s0, $s0, %lo(filemenu_update_show_options_bottom)
/* 168920 802480C0 0C051F9F */  jal       set_window_update
/* 168924 802480C4 0200282D */   daddu    $a1, $s0, $zero
/* 168928 802480C8 24040037 */  addiu     $a0, $zero, 0x37
/* 16892C 802480CC 0C051F9F */  jal       set_window_update
/* 168930 802480D0 0200282D */   daddu    $a1, $s0, $zero
/* 168934 802480D4 0220202D */  daddu     $a0, $s1, $zero
/* 168938 802480D8 0809204E */  j         .L80248138
/* 16893C 802480DC 0000282D */   daddu    $a1, $zero, $zero
.L802480E0:
/* 168940 802480E0 A2200004 */  sb        $zero, 4($s1)
/* 168944 802480E4 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_left)
/* 168948 802480E8 24A533F4 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_left)
/* 16894C 802480EC 0C051F9F */  jal       set_window_update
/* 168950 802480F0 24040033 */   addiu    $a0, $zero, 0x33
/* 168954 802480F4 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_right)
/* 168958 802480F8 24A53468 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_right)
/* 16895C 802480FC 0C051F9F */  jal       set_window_update
/* 168960 80248100 24040034 */   addiu    $a0, $zero, 0x34
/* 168964 80248104 24040035 */  addiu     $a0, $zero, 0x35
/* 168968 80248108 3C108024 */  lui       $s0, %hi(filemenu_update_show_options_bottom)
/* 16896C 8024810C 261034DC */  addiu     $s0, $s0, %lo(filemenu_update_show_options_bottom)
/* 168970 80248110 0C051F9F */  jal       set_window_update
/* 168974 80248114 0200282D */   daddu    $a1, $s0, $zero
/* 168978 80248118 24040037 */  addiu     $a0, $zero, 0x37
/* 16897C 8024811C 0C051F9F */  jal       set_window_update
/* 168980 80248120 0200282D */   daddu    $a1, $s0, $zero
/* 168984 80248124 0809204D */  j         .L80248134
/* 168988 80248128 0220202D */   daddu    $a0, $s1, $zero
.L8024812C:
/* 16898C 8024812C A2230004 */  sb        $v1, 4($s1)
/* 168990 80248130 0220202D */  daddu     $a0, $s1, $zero
.L80248134:
/* 168994 80248134 24050001 */  addiu     $a1, $zero, 1
.L80248138:
/* 168998 80248138 0C090B65 */  jal       filemenu_set_selected
/* 16899C 8024813C 24060002 */   addiu    $a2, $zero, 2
/* 1689A0 80248140 2404002F */  addiu     $a0, $zero, 0x2f
.L80248144:
/* 1689A4 80248144 0C051F9F */  jal       set_window_update
/* 1689A8 80248148 24050002 */   addiu    $a1, $zero, 2
.L8024814C:
/* 1689AC 8024814C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1689B0 80248150 8FB10014 */  lw        $s1, 0x14($sp)
/* 1689B4 80248154 8FB00010 */  lw        $s0, 0x10($sp)
/* 1689B8 80248158 03E00008 */  jr        $ra
/* 1689BC 8024815C 27BD0020 */   addiu    $sp, $sp, 0x20
