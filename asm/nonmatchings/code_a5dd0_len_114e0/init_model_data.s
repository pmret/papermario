.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_model_data
/* AC6E8 80115FE8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* AC6EC 80115FEC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* AC6F0 80115FF0 80420070 */  lb        $v0, 0x70($v0)
/* AC6F4 80115FF4 14400027 */  bnez      $v0, .L80116094
/* AC6F8 80115FF8 00000000 */   nop      
/* AC6FC 80115FFC 3C028015 */  lui       $v0, %hi(gWorldModelList)
/* AC700 80116000 24421770 */  addiu     $v0, $v0, %lo(gWorldModelList)
/* AC704 80116004 3C018015 */  lui       $at, %hi(gCurrentModelListPtr)
/* AC708 80116008 AC2212CC */  sw        $v0, %lo(gCurrentModelListPtr)($at)
/* AC70C 8011600C 3C028015 */  lui       $v0, 0x8015
/* AC710 80116010 24421F70 */  addiu     $v0, $v0, 0x1f70
/* AC714 80116014 3C018015 */  lui       $at, 0x8015
/* AC718 80116018 AC2212E0 */  sw        $v0, 0x12e0($at)
/* AC71C 8011601C 3C028015 */  lui       $v0, 0x8015
/* AC720 80116020 24421F90 */  addiu     $v0, $v0, 0x1f90
/* AC724 80116024 3C018015 */  lui       $at, %hi(gCurrentModelSpecialDlsPtr)
/* AC728 80116028 AC2212E8 */  sw        $v0, %lo(gCurrentModelSpecialDlsPtr)($at)
/* AC72C 8011602C 3C028015 */  lui       $v0, 0x8015
/* AC730 80116030 24422090 */  addiu     $v0, $v0, 0x2090
/* AC734 80116034 3C018015 */  lui       $at, 0x8015
/* AC738 80116038 AC2212B8 */  sw        $v0, 0x12b8($at)
/* AC73C 8011603C 3C028015 */  lui       $v0, 0x8015
/* AC740 80116040 24422214 */  addiu     $v0, $v0, 0x2214
/* AC744 80116044 3C018015 */  lui       $at, 0x8015
/* AC748 80116048 AC2212FC */  sw        $v0, 0x12fc($at)
/* AC74C 8011604C 3C028015 */  lui       $v0, 0x8015
/* AC750 80116050 24422190 */  addiu     $v0, $v0, 0x2190
/* AC754 80116054 3C018015 */  lui       $at, 0x8015
/* AC758 80116058 AC222210 */  sw        $v0, 0x2210($at)
/* AC75C 8011605C 3C028015 */  lui       $v0, 0x8015
/* AC760 80116060 24422220 */  addiu     $v0, $v0, 0x2220
/* AC764 80116064 3C01800A */  lui       $at, 0x800a
/* AC768 80116068 AC22A5F4 */  sw        $v0, -0x5a0c($at)
/* AC76C 8011606C 3C028015 */  lui       $v0, 0x8015
/* AC770 80116070 24423220 */  addiu     $v0, $v0, 0x3220
/* AC774 80116074 3C018015 */  lui       $at, 0x8015
/* AC778 80116078 AC2212F0 */  sw        $v0, 0x12f0($at)
/* AC77C 8011607C 3C028015 */  lui       $v0, 0x8015
/* AC780 80116080 24423228 */  addiu     $v0, $v0, 0x3228
/* AC784 80116084 3C018015 */  lui       $at, 0x8015
/* AC788 80116088 AC223264 */  sw        $v0, 0x3264($at)
/* AC78C 8011608C 03E00008 */  jr        $ra
/* AC790 80116090 00000000 */   nop      
.L80116094:
/* AC794 80116094 3C028015 */  lui       $v0, %hi(gBattleModelList)
/* AC798 80116098 24421B70 */  addiu     $v0, $v0, %lo(gBattleModelList)
/* AC79C 8011609C 3C018015 */  lui       $at, %hi(gCurrentModelListPtr)
/* AC7A0 801160A0 AC2212CC */  sw        $v0, %lo(gCurrentModelListPtr)($at)
/* AC7A4 801160A4 3C028015 */  lui       $v0, 0x8015
/* AC7A8 801160A8 24421F80 */  addiu     $v0, $v0, 0x1f80
/* AC7AC 801160AC 3C018015 */  lui       $at, 0x8015
/* AC7B0 801160B0 AC2212E0 */  sw        $v0, 0x12e0($at)
/* AC7B4 801160B4 3C028015 */  lui       $v0, %hi(gBattleModelSpecialDls)
/* AC7B8 801160B8 24422010 */  addiu     $v0, $v0, %lo(gBattleModelSpecialDls)
/* AC7BC 801160BC 3C018015 */  lui       $at, %hi(gCurrentModelSpecialDlsPtr)
/* AC7C0 801160C0 AC2212E8 */  sw        $v0, %lo(gCurrentModelSpecialDlsPtr)($at)
/* AC7C4 801160C4 3C028015 */  lui       $v0, 0x8015
/* AC7C8 801160C8 24422110 */  addiu     $v0, $v0, 0x2110
/* AC7CC 801160CC 3C018015 */  lui       $at, 0x8015
/* AC7D0 801160D0 AC2212B8 */  sw        $v0, 0x12b8($at)
/* AC7D4 801160D4 3C028015 */  lui       $v0, 0x8015
/* AC7D8 801160D8 24422218 */  addiu     $v0, $v0, 0x2218
/* AC7DC 801160DC 3C018015 */  lui       $at, 0x8015
/* AC7E0 801160E0 AC2212FC */  sw        $v0, 0x12fc($at)
/* AC7E4 801160E4 3C028015 */  lui       $v0, 0x8015
/* AC7E8 801160E8 244221D0 */  addiu     $v0, $v0, 0x21d0
/* AC7EC 801160EC 3C018015 */  lui       $at, 0x8015
/* AC7F0 801160F0 AC222210 */  sw        $v0, 0x2210($at)
/* AC7F4 801160F4 3C028015 */  lui       $v0, 0x8015
/* AC7F8 801160F8 24422A20 */  addiu     $v0, $v0, 0x2a20
/* AC7FC 801160FC 3C01800A */  lui       $at, 0x800a
/* AC800 80116100 AC22A5F4 */  sw        $v0, -0x5a0c($at)
/* AC804 80116104 3C028015 */  lui       $v0, 0x8015
/* AC808 80116108 24423221 */  addiu     $v0, $v0, 0x3221
/* AC80C 8011610C 3C018015 */  lui       $at, 0x8015
/* AC810 80116110 AC2212F0 */  sw        $v0, 0x12f0($at)
/* AC814 80116114 3C028015 */  lui       $v0, 0x8015
/* AC818 80116118 24423248 */  addiu     $v0, $v0, 0x3248
/* AC81C 8011611C 3C018015 */  lui       $at, 0x8015
/* AC820 80116120 AC223264 */  sw        $v0, 0x3264($at)
/* AC824 80116124 03E00008 */  jr        $ra
/* AC828 80116128 00000000 */   nop      
