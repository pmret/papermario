.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_cursor
/* 1637C8 80242F68 3C0A8025 */  lui       $t2, %hi(D_80249B94)
/* 1637CC 80242F6C 254A9B94 */  addiu     $t2, $t2, %lo(D_80249B94)
/* 1637D0 80242F70 3C058025 */  lui       $a1, %hi(D_80249BA0)
/* 1637D4 80242F74 8CA59BA0 */  lw        $a1, %lo(D_80249BA0)($a1)
/* 1637D8 80242F78 8D430000 */  lw        $v1, ($t2)
/* 1637DC 80242F7C 3C013FE0 */  lui       $at, 0x3fe0
/* 1637E0 80242F80 44812800 */  mtc1      $at, $f5
/* 1637E4 80242F84 44802000 */  mtc1      $zero, $f4
/* 1637E8 80242F88 00A31023 */  subu      $v0, $a1, $v1
/* 1637EC 80242F8C 44821000 */  mtc1      $v0, $f2
/* 1637F0 80242F90 00000000 */  nop
/* 1637F4 80242F94 468010A1 */  cvt.d.w   $f2, $f2
/* 1637F8 80242F98 46241082 */  mul.d     $f2, $f2, $f4
/* 1637FC 80242F9C 00000000 */  nop
/* 163800 80242FA0 3C098025 */  lui       $t1, %hi(D_80249B98)
/* 163804 80242FA4 25299B98 */  addiu     $t1, $t1, %lo(D_80249B98)
/* 163808 80242FA8 3C048025 */  lui       $a0, %hi(D_80249BA4)
/* 16380C 80242FAC 8C849BA4 */  lw        $a0, %lo(D_80249BA4)($a0)
/* 163810 80242FB0 8D260000 */  lw        $a2, ($t1)
/* 163814 80242FB4 00861023 */  subu      $v0, $a0, $a2
/* 163818 80242FB8 44820000 */  mtc1      $v0, $f0
/* 16381C 80242FBC 00000000 */  nop
/* 163820 80242FC0 46800021 */  cvt.d.w   $f0, $f0
/* 163824 80242FC4 46240002 */  mul.d     $f0, $f0, $f4
/* 163828 80242FC8 00000000 */  nop
/* 16382C 80242FCC 4620118D */  trunc.w.d $f6, $f2
/* 163830 80242FD0 44073000 */  mfc1      $a3, $f6
/* 163834 80242FD4 4620018D */  trunc.w.d $f6, $f0
/* 163838 80242FD8 44083000 */  mfc1      $t0, $f6
/* 16383C 80242FDC 14A30003 */  bne       $a1, $v1, .L80242FEC
/* 163840 80242FE0 00000000 */   nop
/* 163844 80242FE4 10860007 */  beq       $a0, $a2, .L80243004
/* 163848 80242FE8 00000000 */   nop
.L80242FEC:
/* 16384C 80242FEC 14E00005 */  bnez      $a3, .L80243004
/* 163850 80242FF0 00000000 */   nop
/* 163854 80242FF4 15000003 */  bnez      $t0, .L80243004
/* 163858 80242FF8 00000000 */   nop
/* 16385C 80242FFC AD450000 */  sw        $a1, ($t2)
/* 163860 80243000 AD240000 */  sw        $a0, ($t1)
.L80243004:
/* 163864 80243004 3C038025 */  lui       $v1, %hi(D_80249B94)
/* 163868 80243008 24639B94 */  addiu     $v1, $v1, %lo(D_80249B94)
/* 16386C 8024300C 8C620000 */  lw        $v0, ($v1)
/* 163870 80243010 00471021 */  addu      $v0, $v0, $a3
/* 163874 80243014 AC620000 */  sw        $v0, ($v1)
/* 163878 80243018 3C038025 */  lui       $v1, %hi(D_80249B98)
/* 16387C 8024301C 24639B98 */  addiu     $v1, $v1, %lo(D_80249B98)
/* 163880 80243020 8C620000 */  lw        $v0, ($v1)
/* 163884 80243024 3C048025 */  lui       $a0, %hi(filemenu_cursorGoalAlpha)
/* 163888 80243028 8C849BA8 */  lw        $a0, %lo(filemenu_cursorGoalAlpha)($a0)
/* 16388C 8024302C 00481021 */  addu      $v0, $v0, $t0
/* 163890 80243030 14800009 */  bnez      $a0, .L80243058
/* 163894 80243034 AC620000 */   sw       $v0, ($v1)
/* 163898 80243038 3C038025 */  lui       $v1, %hi(D_80249B9C)
/* 16389C 8024303C 24639B9C */  addiu     $v1, $v1, %lo(D_80249B9C)
/* 1638A0 80243040 8C620000 */  lw        $v0, ($v1)
/* 1638A4 80243044 2442FF80 */  addiu     $v0, $v0, -0x80
/* 1638A8 80243048 0441000D */  bgez      $v0, .L80243080
/* 1638AC 8024304C AC620000 */   sw       $v0, ($v1)
/* 1638B0 80243050 08090C20 */  j         .L80243080
/* 1638B4 80243054 AC600000 */   sw       $zero, ($v1)
.L80243058:
/* 1638B8 80243058 3C038025 */  lui       $v1, %hi(D_80249B9C)
/* 1638BC 8024305C 24639B9C */  addiu     $v1, $v1, %lo(D_80249B9C)
/* 1638C0 80243060 8C620000 */  lw        $v0, ($v1)
/* 1638C4 80243064 24420020 */  addiu     $v0, $v0, 0x20
/* 1638C8 80243068 AC620000 */  sw        $v0, ($v1)
/* 1638CC 8024306C 28420100 */  slti      $v0, $v0, 0x100
/* 1638D0 80243070 14400004 */  bnez      $v0, .L80243084
/* 1638D4 80243074 2404002C */   addiu    $a0, $zero, 0x2c
/* 1638D8 80243078 240200FF */  addiu     $v0, $zero, 0xff
/* 1638DC 8024307C AC620000 */  sw        $v0, ($v1)
.L80243080:
/* 1638E0 80243080 2404002C */  addiu     $a0, $zero, 0x2c
.L80243084:
/* 1638E4 80243084 2406FFFF */  addiu     $a2, $zero, -1
/* 1638E8 80243088 0080282D */  daddu     $a1, $a0, $zero
/* 1638EC 8024308C 3C038016 */  lui       $v1, %hi(D_8015A2D0)
/* 1638F0 80243090 2463A2D0 */  addiu     $v1, $v1, %lo(D_8015A2D0)
.L80243094:
/* 1638F4 80243094 80620003 */  lb        $v0, 3($v1)
/* 1638F8 80243098 10460003 */  beq       $v0, $a2, .L802430A8
/* 1638FC 8024309C 00000000 */   nop
/* 163900 802430A0 54450006 */  bnel      $v0, $a1, .L802430BC
/* 163904 802430A4 24840001 */   addiu    $a0, $a0, 1
.L802430A8:
/* 163908 802430A8 90620000 */  lbu       $v0, ($v1)
/* 16390C 802430AC 30420008 */  andi      $v0, $v0, 8
/* 163910 802430B0 14400005 */  bnez      $v0, .L802430C8
/* 163914 802430B4 00000000 */   nop
/* 163918 802430B8 24840001 */  addiu     $a0, $a0, 1
.L802430BC:
/* 16391C 802430BC 28820040 */  slti      $v0, $a0, 0x40
/* 163920 802430C0 1440FFF4 */  bnez      $v0, .L80243094
/* 163924 802430C4 24630020 */   addiu    $v1, $v1, 0x20
.L802430C8:
/* 163928 802430C8 3C038025 */  lui       $v1, %hi(D_80249BB8)
/* 16392C 802430CC 24639BB8 */  addiu     $v1, $v1, %lo(D_80249BB8)
/* 163930 802430D0 8C620000 */  lw        $v0, ($v1)
/* 163934 802430D4 14400008 */  bnez      $v0, .L802430F8
/* 163938 802430D8 28820040 */   slti     $v0, $a0, 0x40
/* 16393C 802430DC 3C028025 */  lui       $v0, %hi(filemenu_cursorGoalAlpha)
/* 163940 802430E0 8C429BA8 */  lw        $v0, %lo(filemenu_cursorGoalAlpha)($v0)
/* 163944 802430E4 14400004 */  bnez      $v0, .L802430F8
/* 163948 802430E8 28820040 */   slti     $v0, $a0, 0x40
/* 16394C 802430EC 24020001 */  addiu     $v0, $zero, 1
/* 163950 802430F0 AC620000 */  sw        $v0, ($v1)
/* 163954 802430F4 28820040 */  slti      $v0, $a0, 0x40
.L802430F8:
/* 163958 802430F8 1440001E */  bnez      $v0, .L80243174
/* 16395C 802430FC 240200FF */   addiu    $v0, $zero, 0xff
/* 163960 80243100 3C038025 */  lui       $v1, %hi(filemenu_cursorGoalAlpha2)
/* 163964 80243104 8C639BAC */  lw        $v1, %lo(filemenu_cursorGoalAlpha2)($v1)
/* 163968 80243108 14620010 */  bne       $v1, $v0, .L8024314C
/* 16396C 8024310C 00000000 */   nop
/* 163970 80243110 3C038025 */  lui       $v1, %hi(D_80249BB8)
/* 163974 80243114 24639BB8 */  addiu     $v1, $v1, %lo(D_80249BB8)
/* 163978 80243118 8C620000 */  lw        $v0, ($v1)
/* 16397C 8024311C 1040000F */  beqz      $v0, .L8024315C
/* 163980 80243120 2442FFFF */   addiu    $v0, $v0, -1
/* 163984 80243124 1440001A */  bnez      $v0, .L80243190
/* 163988 80243128 AC620000 */   sw       $v0, ($v1)
/* 16398C 8024312C 3C028025 */  lui       $v0, %hi(D_80249BA0)
/* 163990 80243130 8C429BA0 */  lw        $v0, %lo(D_80249BA0)($v0)
/* 163994 80243134 3C038025 */  lui       $v1, %hi(D_80249BA4)
/* 163998 80243138 8C639BA4 */  lw        $v1, %lo(D_80249BA4)($v1)
/* 16399C 8024313C 3C018025 */  lui       $at, %hi(D_80249B94)
/* 1639A0 80243140 AC229B94 */  sw        $v0, %lo(D_80249B94)($at)
/* 1639A4 80243144 3C018025 */  lui       $at, %hi(D_80249B98)
/* 1639A8 80243148 AC239B98 */  sw        $v1, %lo(D_80249B98)($at)
.L8024314C:
/* 1639AC 8024314C 3C028025 */  lui       $v0, %hi(D_80249BB8)
/* 1639B0 80243150 8C429BB8 */  lw        $v0, %lo(D_80249BB8)($v0)
/* 1639B4 80243154 1440000F */  bnez      $v0, .L80243194
/* 1639B8 80243158 240200FF */   addiu    $v0, $zero, 0xff
.L8024315C:
/* 1639BC 8024315C 3C028025 */  lui       $v0, %hi(filemenu_cursorGoalAlpha2)
/* 1639C0 80243160 8C429BAC */  lw        $v0, %lo(filemenu_cursorGoalAlpha2)($v0)
/* 1639C4 80243164 3C018025 */  lui       $at, %hi(filemenu_cursorGoalAlpha)
/* 1639C8 80243168 AC229BA8 */  sw        $v0, %lo(filemenu_cursorGoalAlpha)($at)
/* 1639CC 8024316C 08090C65 */  j         .L80243194
/* 1639D0 80243170 240200FF */   addiu    $v0, $zero, 0xff
.L80243174:
/* 1639D4 80243174 3C028025 */  lui       $v0, %hi(filemenu_cursorGoalAlpha)
/* 1639D8 80243178 8C429BA8 */  lw        $v0, %lo(filemenu_cursorGoalAlpha)($v0)
/* 1639DC 8024317C 14400005 */  bnez      $v0, .L80243194
/* 1639E0 80243180 240200FF */   addiu    $v0, $zero, 0xff
/* 1639E4 80243184 24020001 */  addiu     $v0, $zero, 1
/* 1639E8 80243188 3C018025 */  lui       $at, %hi(D_80249BB8)
/* 1639EC 8024318C AC229BB8 */  sw        $v0, %lo(D_80249BB8)($at)
.L80243190:
/* 1639F0 80243190 240200FF */  addiu     $v0, $zero, 0xff
.L80243194:
/* 1639F4 80243194 3C018025 */  lui       $at, %hi(filemenu_cursorGoalAlpha2)
/* 1639F8 80243198 03E00008 */  jr        $ra
/* 1639FC 8024319C AC229BAC */   sw       $v0, %lo(filemenu_cursorGoalAlpha2)($at)
