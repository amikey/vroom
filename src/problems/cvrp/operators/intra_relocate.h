#ifndef CVRP_INNER_RELOCATE_H
#define CVRP_INNER_RELOCATE_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "algorithms/local_search/ls_operator.h"

class CVRPIntraRelocate : public Operator {
protected:
  virtual void compute_gain() override;

public:
  CVRPIntraRelocate(const Input& input,
                    const SolutionState& sol_state,
                    RawRoute& s_route,
                    Index s_vehicle,
                    Index s_rank,
                    Index t_rank); // relocate rank *after* removal.

  virtual bool is_valid() override;

  virtual void apply() override;

  virtual std::vector<Index> addition_candidates() const override;

  virtual std::vector<Index> update_candidates() const override;
};

#endif